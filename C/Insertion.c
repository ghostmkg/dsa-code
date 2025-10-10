/*
 * C program to insert an element in a specified position in a given array
 */
 
#include <stdio.h>
void main()
{
    int array[100];
    int i, n, x, pos;
 
    printf("Enter the number of elements in the array \n");
    scanf("%d", &n);
    printf("Enter the elements \n");
 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
 
    printf("Input array elements are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nEnter the new element to be inserted: ");
    scanf("%d", &x);
    printf("Enter the position where element is to be inserted: ");
    scanf("%d", &pos);
 
    //shift all elements 1 position forward from the place
    //where element needs to be inserted
    n=n+1;
    for(i = n-1; i >= pos; i--)
        array[i]=array[i-1];
 
    array[pos-1]=x; //Insert the element x on the specified position
 
    //print the new array
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
