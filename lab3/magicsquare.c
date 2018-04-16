
#include <stdio.h>
int main(){
    int a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4;
    int rowa,rowb,rowc,rowd,col1,col2,col3,col4,dia1,dia2;
    
    printf("Please enter the numbers from 1 to 16 in any order: ");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
          &a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4,&c1,&c2,&c3,&c4,&d1,&d2,&d3,&d4);
    printf("%3d%3d%3d%3d\n",a1,a2,a3,a4);
    printf("%3d%3d%3d%3d\n",b1,b2,b3,b4);
    printf("%3d%3d%3d%3d\n",c1,c2,c3,c4);
    printf("%3d%3d%3d%3d\n\n",d1,d2,d3,d4);
    
    rowa = a1 + a2 + a3 + a4;
    rowb = b1 + b2 + b3 + b4;
    rowc = c1 + c2 + c3 + c4;
    rowd = d1 + d2 + d3 + d4;
    
    col1 = a1 + b1 + c1 + d1;
    col2 = a2 + b2 + c2 + d2;
    col3 = a3 + b3 + c3 + d3;
    col4 = a4 + b4 + c4 + d4;
    
    dia1 = a1 + b2 + c3 + d4;
    dia2 = a4 + b3 + c2 + d1;
    
    printf("Row sums: %2d %2d %2d %2d\n", rowa,rowb,rowc,rowd);
    printf("Column sums: %2d %2d %2d %2d\n", col1,col2,col3,col4);
    printf("Diagonal sums: %2d %2d\n", dia1,dia2);
    
   
   return 0; 
}
