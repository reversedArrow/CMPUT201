#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_line(char str[], int n);
int compare(const void *x, const void *y);

int main(void){
  
  int i,j,co, out;
  char temp[21];

  char **str = NULL;

    
    for (i = 0;;i++){
        printf("Enter a word: ");
        out = read_line(temp,21);
	
	str = realloc(str,(i+1)*sizeof(char*));
	str[i] = malloc(21);
	strcpy(str[i],temp);
        if (out == 0)
	  break;

    }
    co = i;

    
    qsort(str,co,sizeof(char *), compare);
    printf("In sorted order: ");
    for (j = 0; j < co; j++){
        printf("%s     ",str[j]);
    }
    printf("\n");
    
    
    for(i=0;i<co;i++)
    {
        free(str[i]);
    }
}

int read_line(char str[], int n){
    int ch, i = 0;
    while ((ch = getchar())!= '\n')
        if (i<n)    str[i++] = ch;
    str[i] = '\0';
    return i;
}
int compare(const void *x, const void *y){
    return strcmp(*(char **)x,*(char **)y);
}
