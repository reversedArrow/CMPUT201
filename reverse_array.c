/* reverse.c */
#include <stdio.h>
int main()
{
    int a[10] , *p;
    printf("Enter 10 elements: ");
    for(p = a ; p < a+10 ; p++)
        scanf("%d",p);
    
    printf("Elements in reversed order: ");
    for(p = a+9 ; p >= a ; p--)
        printf("%d    ",*p);
    printf("\n");
    return 0;
}
