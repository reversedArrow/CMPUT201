#include<stdio.h>
#include<stdlib.h>

void init_array(int n, char array[n][n]);
void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

void init_array(int n, char array[n][n]){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      array[i][j]=0;
    }
  }
}
void create_magic_square(int n, char magic_square[n][n]){
  int row = 0, col = n/2;
  int exrow = row;
  int excol = col;
  for (int i=1; i<n*n; i++){

    row--;
    col++;
    if (row<0)
      row = n-1;
    if (col>n-1)
      col = 0;
    if (magic_square[row][col]!=0){
      exrow++;
      if (exrow>n-1){
	exrow = 0;
      }
      row = exrow;
      col = excol;
    }
    magic_square[row][col] = i+1;
       //continue;}
  }
}

void print_magic_square(int n, char magic_square[n][n]){
  for (int i = 0; i<n; i++){
    for (int j = 0; j<n; j++){
      printf("%d\t",magic_square[i][j]);
    }
    printf("\n");
  }
}
    
int main(){

  int n,m;

  printf("This program creates a magic square of a specified size.\n");
  printf("This size must be an odd number between 1 and 99.\n");
  printf("Enter size of magic square:");
  scanf("%d",&n);
  m = n/2;
  if (n%2 == 0 || n<1 || n>99){
    printf("invalid size\n");
    return -1;
  }
  char matrix[n][n];

  init_array(n,matrix);

  matrix[0][m] = 1;

  create_magic_square(n,matrix);

  print_magic_square(n,matrix);

  return 0;
}

