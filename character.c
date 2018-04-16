#include<stdio.h>
#include<ctype.h>


int main(){
    char ch;
    //int i;

    ch = toupper(ch);

    //i = ch;
    scanf("c",&ch);

    //for (i = ch; ch<='Z'; ch++)
        //printf("character: %d\n",i);
    if ('a'<=ch && ch<= 'z')
       ch = ch-'a'+'A';

    //scanf("%c",&ch);

    printf("%c",ch);

    return 0;

}
