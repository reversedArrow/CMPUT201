#include<stdio.h>
 
int main() {
   int n,i,j,k, a=1;
   printf("Enter: ");
   scanf("%d",&n);
   int matrix[n][n];
   
   for (i = 0; i<n; i++){
      for (j = 0; j<n; j++){
         matrix[i][j] = a;
         a++;
        }
      }
   for (i = 0; i<n; i++){
      for (j = 0; j<n; j++){
   	 printf("%d\t",matrix[i][j]);
   	}
         printf("\n");
      
   }
   return (0);
}
