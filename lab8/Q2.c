#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 100

int main(){
  char string2[N] ;
  int i,j, length,k = 0;
  int pa = 0;
  char string[N];
    
  printf("Enter a string: ");
    
  fgets(string2,N,stdin);
  for (i = 0; i<strlen(string2); i++){
    if(isalpha(string2[i])){
      string[k] = string2[i];
      k++;

    }
    string[k] = '\0';


      
  }
    
    
  length = strlen(string);
  printf("%s\n",string);
    
  for(j = 0;j < length ;j++){

    if(string[j] != string[length-j-1]){
      pa = 1;
      break;
    }
  }
    
  if (pa) {
    printf("%s is not a palindrome\n", string);
  }    
  else {
    printf("%s is a palindrome\n", string);
  }
  return 0;
}
