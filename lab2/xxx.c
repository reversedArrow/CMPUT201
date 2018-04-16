#include<stdio.h>
//#include<conio.h>

//int horner(int,int);
//int count = 0;


int main()
{
//    int n,x,h=0;
    int n = 6
    float a[6] = {-6,7,-1,-5,2,3};
//    scanf("%d%d,&n,&x");
//    h = horner(n,x);
//    printf("%d",h);
//    getch();
//}
    float x,y;

    scanf("enter:%f", &x);
    y = horner(n,a,x);
//int horner(int n, int x){
//    if (count! = n)
//    {
//       count++;
//       printf("%d+%d*(,count-1,x");
//       return (count-1 + x*horner(n,x));
//     }    
    serial.print(x,2); serial.print(" "); serial.printly(y,2);
}
float horner(int n, float*c, float x){
      floatf;
      f = c[0];
      for (int i = 1;i<n; i++){
          f = f*x+c[i];
      }
      return(f);
}
//while (1){
//      int i;
//      for i in length a[6] downto 1 do
//      y = (y*x)+a[i];
//      prinf("sum is %d", y);
//     return count;\
//         }

