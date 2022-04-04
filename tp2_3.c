#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7

int main(){
  int i,j;
  int mt[N][M], *p_mt;
  p_mt = &mt[0][0];
  for ( i = 0; i < N; i++)
  {
  for(j = 0;j<M; j++)
  {
      *(p_mt+(i*M+j)) = 1+rand()%100;
      printf("%d ",(*p_mt)++);
  }
  printf("\n");
  }
  
  
scanf(" %c");
return 0;
}