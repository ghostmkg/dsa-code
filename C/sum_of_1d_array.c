#include <stdio.h>

int main()
{
    int n;
    int sum=0;
    printf("Enter the number of elements in array\n");
    scanf ("%d",&n);
    int arr[n];

    printf("Enter the elements of array\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("The sum is %d\n",sum);
}