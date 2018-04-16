#include<stdio.h>

int main()
{
  float balancea, balanceb, balancec, loan, rate, pay, a, b, c,remaining;
    int i;

    printf("Enter amount of loan: ");
    scanf("%f",&loan);
    printf("Enter interest rate: ");
    scanf("%f",&rate);
    printf("Enter the number of months to pay back: ");
    scanf("%f",&pay);
    
    a = loan - pay;
    balancea = a + loan*(rate/1200);
    b = balancea - pay;
    balanceb = b + balancea*(rate/1200);
    c = balanceb - pay;
    balancec = c + balanceb*(rate/1200);

    remaining = loan;
    
    for (i = 1; i<pay+1; i++){
      
      remaining = remaining - remaining*(rate/1200);
      
      printf("Balance remaining after %d payment: %.2f\n", i,remaining);
    }
    
    

      //printf("Balance remaining after first payment: %.2f\n", balancea);
      //printf("Balance remaining after second payment: %.2f\n", balanceb);
      // printf("Balance remaining after third payment: %.2f\n", balancec);
    return 0;
}
