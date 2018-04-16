#include<stdio.h>


int main(){

  int t2;
  long in, f_int,remainder, t1;
  double fra,f_fra,remainder2;
  double binary;
  printf("Enter the floating-point number: ");
  scanf("%ld.%lf",&in,&fra);
  while (fra>1)
    fra = fra/10;

  t1 = 1;
  f_int = 0;
  remainder2 = 0.1;
  f_fra = 0.0;

    
  while (in > 0){
    remainder = in%2;
    f_int = f_int + remainder*t1;
    in = in/2;
    t1 = t1*10;
  }

  
  for (int i = 1; i<=24; i++){
    fra = fra*2;    
    if (fra>1)
      t2 = 1;
    else
      t2 = 0;
    f_fra = f_fra + remainder2*t2;
    if (t2 == 1)
      fra = fra - t2;
    remainder2 = remainder2/10;
}

  binary = f_int + f_fra;
  
  
  printf("In binary format: %lf\n", binary);
  return 0;
}

