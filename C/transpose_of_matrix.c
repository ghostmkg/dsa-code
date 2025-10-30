#include<stdio.h>
int main()
{
    int a[3][3],b[3][3],i,j;
    printf("Enter 9 elements of the matrix");
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
           printf("%d ",b[i][j]);
        }
        printf("\n");
    }

}