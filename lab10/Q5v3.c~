#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define totalWards 20
#define length 20

int read_line(char *, int);

int main(void)
{
  char *words[length], temp[20];
  char word[totalWards + 1];
  int i, j, len, mark = 0;
  for (;;)
    {
      if (mark == length)
	{
	  printf("\n..Length is full..\n");
	  break;
	}
      // promt the input from user
      printf("Enter a word: ");
      //call the read_line method
      len = read_line(word, totalWards);
      if (len == 0)
	break;
      *(words + mark) = malloc(len);
      if (*(words + mark) == NULL)
	{
	  printf("\nmalloc failed %d of words!\n", mark);
	  exit(EXIT_FAILURE);
	}
      strcpy(*(words + mark), word);
      ++mark;
    }

  
  //sort the words
  for (i = 0; i<mark - 1; i++)
    {
      for (j = i + 1; j<mark; j++)
	{
	  if (strcmp(*(words + i), *(words + j))>0)
	    {
	      strcpy(temp, *(words + i));
	      strcpy(*(words + i), *(words + j));
	      strcpy(*(words + j), temp);
	    }
	}
    }

  
  //display words after sorting
  printf("\nIn sorted order:");
  for (i = 0; i < mark; ++i)
    {
      printf(" %s", *(words + i));
      free(*(words + i));
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
