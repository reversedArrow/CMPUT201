#include<stdio.h>

int main()
{
    int x;
    float y;    
    
    while (1)
    {
        printf("Please enter a value for x to evaluate the polynomial: \n");
    
        if (scanf("%d",&x)==1)
        {
       
             y = 3*x*x*x*x*x+2*x*x*x*x-5*x*x*x-x*x+7*x-6;

             printf("The value of the polynomial is: %.2f\n", y);
        }
        else
            break;
    }
    return 0;
}
