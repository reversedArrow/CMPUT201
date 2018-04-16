#include<stdio.h>

int main()
{
  int a, b, c, d, e;

  printf("Enter a three-digit number: ");
  scanf("%3d",&a);
  b = a%10;
  c = a/100;
  d = a/10;
  e = d%10;

  printf("The reversal is: %1d%1d%1d\n", b, e, c);

  return 0;
}

