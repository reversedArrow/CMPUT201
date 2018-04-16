#include<stdio.h>

#define N = 10                        //error. "=" should be removed
#define INC(x) x+1
#define SUB(x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
    int a[N], i, j, k, m;

#ifdef N
    i = j;                            // undefined variable j. j haven't been initialized.
#else
    j = i;
#endif

    i = 10 * INC(j);                 // undefined variable j. j haven't been initialized.
    i = SUB(j, k);                   // undefined variable j,k. j,k haven't been initialized.
    i = SQR(SQR(j));                 // undefined variable j. j haven't been initialized.
    i = CUBE(j);                     // undefined variable j. j haven't been initialized.
    i = M1(j, k);                    // undefined variable j,k. j,k haven't been initialized.
    puts(M2(i, j));                  // undefined variable j. j haven't been initialized.

#undef SQR                           // #undef SQR(???)
    i = SQR(j);                      // SQR was undefined the line before
#define SQR                          // #define SQR(???)
    i = SQR(j);                      // j would not be taken.

    return 0;
}




//**************************************************************


