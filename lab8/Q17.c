#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdbool.h>



bool is_palindrome(const char *message);



int main(void){
  char string1[100] = {0};
  int i, k = 0;
    char string[100];
    bool flag;
    printf("Enter a string:");
    
    fgets(string1,100,stdin);
    for (i = 0; i<100; i++){
      if(isalpha(string1[i])){
	
	
	string[k] = string1[i];
	k++;
	
      }
      string[k] = '\0';
      
    }
    
    
    flag = is_palindrome(string);
    
    if (flag) {
      printf("%s is not a palindrome\n", string);
    }    
    else {
      printf("%s is a palindrome\n", string);
    }
    return 0;
}

bool is_palindrome(const char *message){
    char p, k;
    int c = 1;
    int len = strlen(message);
    printf("%s\n",message);
    p = message[0];
    k = message[len-1];    len--;
    for (;;){
       if (p == '\0')	break;
       if (p != k)	return false;
       p = message[++c];
       k = message[--len];
    }
    return true;
}




