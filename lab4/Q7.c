#include<stdio.h>

int main(){
  int a, b, c, d, max1, max2, min1, min2;
  printf("Enter four integers: ");
  scanf("%d%d%d%d",&a,&b,&c,&d);
  if (a > b)
    max1 = a;
  else
    max1 = b;
  if (a > b)
    min1 = b;
  else
    min1 = a;
    
  if (c > d)
    max2 = c;
  else
    max2 = d;
  if (c > d)
    min2 = d;
  else
    min2 = c;
  
  if (max1 > max2)
    printf("Largest: %d\nSmallest: %d\n", max1, min2);
  else
    printf("Largest: %d\nSmallest: %d\n", max2, min1);

    return 0;  
}
