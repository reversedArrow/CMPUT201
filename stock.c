#include<stdio.h>

int main()
{

    int price, shares;
    float num, denom, value;
  
    printf("enter share price(must include a fraction): ");
    scanf("%d%f/%f",&price,&num,&denom);
    printf("enter unmber of shares; ");
    scanf("%d", &shares);
  
    value = (price + num / denom) * shares;
    printf("value of holding: $%.2f\n", value);
    return 0;
}
