#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define totalWards 20

int read_line(char *, int);
int compare(const void *x, const void *y);

int main(void)
{
  //char *words[20], temp[20];
  //char word[totalWards + 1];
  int i, j, co, out;

  char **str = (char **)malloc(1000*sizeof(char));
  
  
  for (i = 0;i<21 ;i++)
    {
      str[i] = (char *)malloc(21*sizeof(char *));
      
      for (i = 0; ;i++){
	
	
	printf("Enter a word: ");
	
	out = read_line(str[i], 21);
      
      if (out == 0)
	break;
      }
    }
  co = i;
      //*(words + mark) = malloc(len);
      //if (*(words + mark) == NULL)
      //{
      // printf("\nmalloc failed %d of words!\n", mark);
      // exit(EXIT_FAILURE);
      //}
      //strcpy(*(words + mark), word);


  
  //sort the words
  //for (i = 0; i<mark - 1; i++)
  //{
  //  for (j = i + 1; j<mark; j++)
  //	{
  //	  if (strcmp(*(words + i), *(words + j))>0)
  //	    {
  //	      strcpy(temp, *(words + i));
  //	      strcpy(*(words + i), *(words + j));
  //	      strcpy(*(words + j), temp);
  //	    }
  //	}
  //}

  qsort(str,co,sizeof(char *), compare);

  
  //display words after sorting
  printf("\nIn sorted order:");
  for (j = 0; j < co; j++)
    {
      printf(" %s", str[j]);
      printf(" \t");
    }
  printf("\n");
  return 0;
}

int read_line(char *str, int n)
{
  int ch, i = 0;
  while (!isspace(ch = getchar()))
    if (i < n)
      *(str + i++) = ch;
  while (ch != '\n')
    ch = getchar();
  *(str + i) = '\0';
  return i;
}

int compare(const void *x, const void *y){
  
  return strcmp(*(char **)x,*(char **)y);
}
