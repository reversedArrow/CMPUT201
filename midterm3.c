#include<stdio.h>


int main(){
  int large, slarge, temp, low;

  printf("enter 4 int: \n");
  scanf("%d%d%d",&large,&slarge,&temp,&low);

  if (slarge>large)
    large = slarge;
  if (temp>large){
    large = temp;
    if (){
