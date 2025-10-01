#include <stdio.h>

int binary(int low,int high,int target,int arr[])
{
    int mid = (low+high)/2;
    if (low>high)
    return -1;
    if (arr[mid]==target)
    return mid;
    else if (arr[mid]<target)
    return binary(mid+1,high,target,arr);
    else
    return binary(low,mid-1,target,arr);
}

int main()
{
    int n;
    int target;
    int result;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array\n");
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    for (int i=0;i<n;i++)
    printf("%d ",arr[i]);
    
    printf("\n");
    printf ("Enter which number to search\n");
    scanf("%d",&target);

    result = binary(0,n-1,target,arr);
    if (result == -1)
    printf("The number is not found in the array\n");

    else
    printf("The number is found at index %d\n",result);
    
}