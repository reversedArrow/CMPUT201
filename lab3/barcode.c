#include<stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, adjustedTotal, lastDigit, remainder;
    //float remainder;

    while (1)
    {
        printf("Enter the first digit: ");
        if (scanf("%1d",&d)==1)
        {
             printf("Enter first group of five digits: ");
             scanf("%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5);
             printf("Enter second group of five digits: ");
             scanf("%1d%1d%1d%1d%1d",&j1,&j2,&j3,&j4,&j5);

             first_sum = d + i2 + i4 + j1 + j3 + j5;
             second_sum = i1 + i3 + i5 + j2 + j4;
             total = 3 * first_sum + second_sum;
             adjustedTotal = total - 1;
             remainder = adjustedTotal%10;
	     //printf("%.2f\n",remainder);
	     if (remainder>=0){
	       
	       lastDigit = 9 - remainder;
	      
	     }
	     else{
	       lastDigit = 0;
	       
	     }
	     printf("Check digit: %d\n", lastDigit);
	}
    }
    return 0;
}
