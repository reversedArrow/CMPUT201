#include<stdio.h>

int main(){
  int i,j,n = 0,a = 1;
  int array[5][5];
	 
  for (i = 0;n<5; i--,n++){
    if(i ==  (-1)){
    i = 4;
    }

    for (j = 0; n<5; j++,n++){
      if (j == 5){
	j = 0;
      }
      array[i][j] = a;
      a++;
    }
  }
      
  for (i = 0; i<5; i++){
    for (j = 0; j<5; j++){
    printf("%d\t",array[i][j]);}
    printf("\n");}
  return 0;
}
	 
