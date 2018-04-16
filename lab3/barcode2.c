#include<stdio.h>

int main(void)
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, adjustedTotal, lastDigit;
    float remainder;

    // while (1)
    // {
        printf("Enter the first 11 digit of a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d,&i1,&i2,&i3,&i4,&i5,&j1,&j2,&j3,&j4,&j5);
	   //if (scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d,&i1,&i2,&i3,&i4,&i5,&j1,&j2,&j3,&j4,&j5)==1)
        //{
	  //printf("Enter first group of five digits: ");
	  //scanf("%1d%1d%1d%1d%1d",&i1,&i2,&i3,&i4,&i5);
	  //printf("Enter second group of five digits: ");
	  //scanf("%1d%1d%1d%1d%1d",&j1,&j2,&j3,&j4,&j5);

             first_sum = d + i2 + i4 + j1 + j3 + j5;
             second_sum = i1 + i3 + i5 + j2 + j4;
             total = 3 * first_sum + second_sum;
             adjustedTotal = total - 1;
             remainder = adjustedTotal%10;
	     //printf("%.2f\n",remainder);
	     lastDigit = 9 - remainder;             
             //lastDigit = 9 - (int)(remainder + 0.5);

             printf("Check digit: %d\n", lastDigit);
	     //}   
	     //else
	     //break;    
	     //}
    return 0;
}
