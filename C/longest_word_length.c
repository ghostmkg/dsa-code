#include <stdio.h>
#include <string.h>
int length(char str[])
{
    int maxlen=0;
    int curr=0;

    int len = strlen(str);
    if (str[len-1] == '\n') 
    str[len-1] = '\0';

    for (int i=0;str[i]!='\0';i++)
    {
        if (str[i]!=' ')
        curr++;
        else
        {
            if(curr>maxlen)
            maxlen=curr;
            curr=0;
        }
        if (curr > maxlen)
        maxlen = curr;
    }
    return maxlen;
}

int main()
{
    char str[100];
    printf("Enter the string\n");
    fgets(str,sizeof(str),stdin);
    printf("%d\n",length(str));
}