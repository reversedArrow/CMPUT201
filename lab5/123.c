#include<stdio.h>
#include<stdlib.h>



void init_array(int array[], int length){
  for(int i=0; i<length; i++){
    array[i]=0;
  }
}



int main(){

  int i,n;
  //int a[99][99];

  printf("This program creates a magic square of a specified size.\n");
  printf("This size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square:");
  scanf("%d",&n);
  if (n%2 == 0 || n<1 || n>99){
    printf("invalid size\n");
    return -1;
  }
  int matrix[n][n];
  int m = n/2;

  for(int i=0; i<n; i++)
    {
      init_array(matrix[i], n);
    }

  


  matrix[0][m] = 1;


  int row = 0;
  int col = m;
  int exrow;
  int excol;

  
  for (i=2,row = 0, col = m; i<((n*n)+1); i++){


    
    //check the row
    if ((row - 1) < 0) { 
      exrow = n - 1; 
    }
    else {
      exrow = row - 1;
    }



    

    //check the col
    if ((col + 1) > (n - 1)) { 
      excol = 0;                            
    }
./    else {
      excol = col + 1;
    }



    
    if (matrix[exrow][excol] > 0) {      
      //out of bound, reset row
      if (row > (n - 1)) {            
	exrow = 0;                               
      }                                                                   
      else {                                                              
	exrow = row + 1;	
	excol = col;                        
      }                                                                     
    }


    
    row = exrow;                                                         
    col = excol;
    printf("number  %d  row  %d  col %d\n",i,row,col);
    matrix[row][col] = i;            
  }





  //print the matrix
  for (i = 0; i<n; i++){
     for (int j = 0; j<n; j++){
        printf("%d\t",matrix[i][j]);
	}
         printf("\n");
  }

  return 0;
}
