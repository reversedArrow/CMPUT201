#include<stdio.h>

int main(){
  int a,b,c,d;
  float high1, high2, low1, low2, slarge;

  printf("Enter 4 integer: \n");
  scanf("%d%d%d%d",&a,&b,&c,&d);


  if (a>b){
    high1 = a;
    low1 = b;
  }
  else{
    high1 = b;
    low1 = a;
  }
  if(c>d){
    high2 = c;
    low2 = d;
  }
  else{
    high2 = d;
    low2 = c;
  }
  if (high1>high2 && high2>low1){
    slarge = high2;
  }
  else if(high1>high2 && high2<low1)
    slarge = low1;
  else if(high1<high2 && high1>low2){
    slarge = high1;
  }
  else if(high1<high2 && high1<low2)
    slarge = low2;
  
  printf("second largest is %.0f: \n", slarge);
  
  return 0;
}  
  
