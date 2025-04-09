#include <cstdio>
#include <cmath>

void navie_softmax(float *dst,float *src,const int data_size){
  float sum=0.f;
  for (int i=0;i<data_size;++i){
    sum+=expf(src[i]);
  }

  for (int i=0;i<data_size;++i){
    dst[i]=expf(src[i])/sum;
  }
}


int main(void){
  const int data_size=10;
  float *src=new float[data_size];
  float *dst=new float[data_size];

  for (int i=0;i<data_size;++i){
    src[i]=i+i;
  }

  navie_softmax(dst,src,data_size);

  for (int i=0;i<data_size;++i){
    printf("%2.5f\t",dst[i]);
  }
  printf("\n");

  delete src;
  delete dst;
  return 0;
}
