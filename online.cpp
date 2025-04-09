#include <cfloat>
#include <cstdio>
#include <cmath>

void online_softmax(float *dst,float *src,const int data_size){
  float old_max=-FLT_MAX;
  float sum=0.0f;
  for (int i=0;i<data_size;++i){
    float new_max=std::max(old_max,src[i]);
    sum=sum*expf(old_max-new_max)+expf(src[i]-new_max);
    old_max=new_max;
  }

  for (int i=0;i<data_size;++i){
    dst[i]=expf(src[i]-old_max)/sum;
  }
}


int main(void){
  const int data_size=10;
  float *src=new float[data_size];
  float *dst=new float[data_size];

  for (int i=0;i<data_size;++i){
    src[i]=i+i;
  }

  online_softmax(dst,src,data_size);

  for (int i=0;i<data_size;++i){
    printf("%2.5f\t",dst[i]);
  }
  printf("\n");

  delete src;
  delete dst;
  return 0;
}
