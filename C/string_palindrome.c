#include <stdio.h>
#include <string.h>

void palin(int start , int end , char str[])
{
    if (str[start]!=str[end])
    {
    printf("The string is not a palindrome");
    return;
    }
    if (start>=end)
    {
    printf("The string is a palindrome");
    return;
    }
    palin(start+1,end-1,str);
}


int main()
{
    char str[100];
    printf("Enter the string\n");
    scanf("%s",str);
    size_t n = strlen(str);
    palin(0,n-1,str);
}