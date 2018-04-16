#include <stdio.h>

int main(void)
{
  int n, dn, x, y, remainder,GCD;

    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &dn);

    x = n;
    y = dn;

    /* compute GCD */
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    GCD = x;

    /* reduce fraction to lowest terms */
    n /= x;
    dn /= x;

    printf("In lowest terms: %d/%d\n", n, dn);

    return 0;
}
