#include<stdio.h>


int main()
{
    float a;
    int b;
    printf("please enter a: \n");
    scanf("%f", &a);
    b = (int)(a+0.5);
    printf("adjusted a = %d\n", b);

    return 0;
}
