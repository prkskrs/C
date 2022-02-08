#include<stdio.h>
#include<string.h>


int brute(char text[],char pattern[])
{
    int n=strlen(text);
    int m=strlen(pattern);
    for (int i = 0; i < n; i++)
    {
        int j=0;
        while (j<m && pattern[j]==text[i+j])
        {
            j++;
        }
        if (j==m)
        {
            return i+1;
        }
        
        
        
    }
    return -1;
    
}


int main()
{
    char *text="abctdbcbdcdbdbcvfd";
    char *pattern="bcv";

    int found=brute(text,pattern);
    if(found>=0)
    {
        printf("found at %d\n",found);
    }
    else
    {
        printf("not found\n");

    }


    // printf("%s\n",pattern);
}
