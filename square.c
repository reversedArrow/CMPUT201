#include<stdio.h>

int main(){
  int i, n, odd, square;

  printf("This program print a table of squares\n");
  printf("Start number: ");
  scanf("%d",&n);

  i = 1;
  odd = 3;
  for (square = 1; i<=n; odd+=2){
    printf("%10d%10d\n",i,square);
    ++i;
    square+=odd;
  }
  return 0;
    }
