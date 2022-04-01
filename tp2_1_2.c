#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
  int i;
  int vt[N],*p_vt;
  p_vt = vt;
  for ( i = 0; i < N; i++)
  {
      *p_vt = 1+rand()%100;
      printf("%d ",*p_vt++);
  }
  
  
scanf(" %c");
return 0;
}