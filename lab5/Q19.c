#include <stdio.h>
#include <stdlib.h>

void pb(int n);

void pb(int n)
{
    if(n!=0)
    {
        pb(n/2);
        putchar('0'+n%2);
    }
    
}



int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    pb(n);
    printf("\n");
    return 0;
}


