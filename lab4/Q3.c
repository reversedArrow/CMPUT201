#include<stdio.h>

int main(){
  int n, m, i, nn, nm, gcd;

  printf("Enter a fraction: ");
  scanf("%d/%d", &n, &m);

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
  nn = n/gcd;
  nm = m/gcd;
  if (nm==0||m==0){
    printf("denominitaor can not be 0!!\n");
  }
  else
    
    printf("In lowest terms: %d/%d\n", nn,nm);
  
  return 0;
}
