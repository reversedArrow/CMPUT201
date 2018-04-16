#include<stdio.h>
#include<stdlib.h>




void quicksort(int a[], int left, int right);
int split(int a[], int left[], int right);



int main(){
	int n;
	int i;

	printf("Enter the length of the array: ");
	scanf("%d",&n);
	int a[n];

	printf("Enter %d integers: ",n);
	for (i = 0; i<n; i++)
	   scanf("%d",&a[i]);

	quicksort(a,0,n-1);

	printf("The sorted array is: ");
	for (i = 0; i<n; i++)
	   printf("%d\t",a[i]);
	printf("\n");

	return 0;
} 

void quicksort(int a[n], int left, int right){
    int middle;
    if (left>=right)
      return;
    middle = split(a,left,right);
    quicksort(a,left,middle-1);
    quicksort(a,middle+1,right);
    return;
}

int split(int a[n],int left; int right){
   int pivot = a[left];
   int b[right - left +1];
   int i,j;
   j = 0;
   k = right - left;
   for (i = left+1;i<=right;i++)
      if (a[i]<=pivot)
	b[j++] = a[i];
      else
	b[k--] = a[i];
   b[j] = pivot;
   j = 0;
   for (i = left; i<=right; i++,j++)
      a[i] = b[j]
   return k;
}























