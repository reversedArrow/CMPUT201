#include<stdio.h>
#include<string.h>
char name[50] = {0};
int result;
int main()
{
    printf("Hello word!\n");
    printf("what's your name?");
    fgets(name,50,stdin);
    printf("greatings %s",name);
    printf("are you a sha bi?(1 stand for yes/2 stand for no)");
    scanf("%d",&result);
    while (result == 1){
      printf("you admit youself is a sha bi !! you are a real sha bi !\n");
      return 0;
    }
    while (result == 2){
      printf("unexpectedly answered this question, you are a sha bi !\n");
      return 0;
    }
}
