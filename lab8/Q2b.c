#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
  char string1[100] = {0};
  int i,k = 0;
  char string[100];
  char *p,*t;
  int mid, pa,len;
  printf("Enter a string:");
    
  fgets(string1,100,stdin);
  for (i = 0; i<100; i++){
    if(isalpha(string1[i])){
	
	
      string[k] = string1[i];
      k++;
	
    } 
    string[k] = '\0';
      
  }
  len = strlen(string);
  while (string[len]!= '\0')
    {
      len++;
    }

  p = &string[0];
  t = p+(len-1);
  mid = (len/2)+1;
  for (i = 0; i<mid;i++){
    printf("%c%c\n",*p,*t);
    
    if(*p==*t){
      
      pa = 0;
      
    }
    
    else{
      pa = 1;
      break;
    }
    p++;
    t--;
  }
  len--;
  i++;
    
  if (pa==1) {
    printf("%s is not a palindrome\n", string);
  }    
  else {
    printf("%s is a palindrome\n", string);
  }
  return 0;
}
