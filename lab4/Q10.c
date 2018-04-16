#include<stdio.h>

int main(){
  int num, lnum;
  printf("Enter numerical grade: ");
  scanf("%d", &num);


  if (num<0||num>100){
    printf("Please enter the valid grade!\n");
    return 0;
      }
  
  lnum = num/10;
  
  
  switch (lnum){
  case 10: printf("Letter grade: A\n");
  break;
  case 9: printf("Letter grade: A\n");
  break;
  case 8: printf("Letter grade: B\n");
  break;
  case 7: printf("Letter grade: C\n");
  break;
  case 6: printf("Letter grade: D\n");
  break;
  case 5: printf("Letter grade: F\n");
  break;
  case 4: printf("Letter grade: F\n");
  break;
  case 3: printf("Letter grade: F\n");
  break;
  case 2: printf("Letter grade: F\n");
  break;
  case 1: printf("Letter grade: F\n");
  break;
  case 0: printf("Letter grade: F\n");
  break;
  default: printf("Illegal grade\n");
  break;
  }

  return 0; 
}
