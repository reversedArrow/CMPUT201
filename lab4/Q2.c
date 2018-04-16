#include<stdio.h>

int main(){
  int n, m, i, gcd;

  printf("Enter two integers: ");
  scanf("%d %d", &n, &m);

  if (n == 0)
    gcd = m;
  if (m == 0)
    gcd = n;

  for (i=1;i<=n && i<=m; ++i){
      //while (n != m){
      //if (n > m)
      //n -=m
      //else
      //m -= n
    //printf("Greatest common divisor: %d",n);
    //break;
    if (n%i == 0 && m%i == 0)
      gcd = i;
    }

  printf("Greatest common divisor: %d\n", gcd);
  
  return 0;
}
