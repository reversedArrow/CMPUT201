#include<stdio.h>

int main(){

  long in,remainder,remainder2,remainder3, t1,t2, f_int, f_fra, fra,k;

  printf("Enter the floating-point number: ");
  scanf("%f",&fra);


  t2 = 0.1f;
  f_fra = 0;

    

  
  while (fra > 0.0000000000000001 ){
    k = fra*2;
    if (k<1){
      remainder2 = 0;
    }
    else{
      remainder2 = 1;
    }
    f_fra = f_fra + remainder2*t2;
    
    fra = fra*2;
    t2 = t2/10;
    if (fra>1){
      fra = fra-1;
    }
  }
    

  
  printf("In binary format: %f\n",f_fra);
  return 0;
}
