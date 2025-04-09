
#include <cstdio>
#include <cmath>
#include <cfloat>

void safe_softmax(float *dst,float *src,const int data_size){
  float max_value=-FLT_MIN;
  for (int i=0;i<data_size;++i){
    if(src[i]>max_value){
      max_value=src[i];
    }
  }
  float sum=0.f;
  for (int i=0;i<data_size;++i){
    sum+=expf(src[i]-max_value);
  }

  for (int i=0;i<data_size;++i){
    dst[i]=expf(src[i]-max_value)/sum;
  }
}


int main(void){
  const int data_size=10;
  float *src=new float[data_size];
  float *dst=new float[data_size];

  for (int i=0;i<data_size;++i){
    src[i]=i+i;
  }

  safe_softmax(dst,src,data_size);

  for (int i=0;i<data_size;++i){
    printf("%2.5f\t",dst[i]);
  }
  printf("\n");

  delete src;
  delete dst;
  return 0;
}
