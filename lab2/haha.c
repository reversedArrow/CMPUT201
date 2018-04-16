#include<stdio.h>

int main()
{
    int x;
    float a, b, c, d, e, f;
 
    printf("please enter balabalabala : ");
    scanf("%d",&x);
    a = 3*x+2;
    b = a*x-5;
    c = b*x-1;
    d = c*x+7;
    e = d*x-6;
     
    //a = x-6;
    //b = a+7;
    //c = x-1;
    //d = x-5;
    //e = 3*x + 2;
    //f = a*b*c*d*e;
 
    printf("the value is: %.2f\n", e);
    return 0;
}
