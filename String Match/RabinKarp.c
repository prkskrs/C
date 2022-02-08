#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define d 10

void rabinKarp(char pattern[],char text[],int q)
{
    int m=strlen(pattern);
    int n=strlen(text);
    int p=0;// hash value of pattern
    int t=0;// hash value of text
    int h=1;
    int i,j;
    // h value

    for (int i = 0; i < m-1; i++)
    {
        h=(h*d)%q;

    }

    //find hash value for pattern and text

    for (int i = 0; i < m; i++)
    {
        p=(d*p+pattern[i])%q;     
        t=(d*t+text[i])%q; 
    }
    // find match
    for (int i = 0; i <=n-m; i++)
    {
        if(p==t)
        {
            for (int j = 0; j < m; j++)
            {
                if (text[i+j]!=pattern[j])   // checking every character if hash value is matched
                {
                    break;
                }
            }
            if(j==m){
                    printf("Pattern is found at position: %d\n",i+1);
                }
        }
            
        if (i<n-m){
                    t=(d*(t-text[i]*h)+text[i+m])%q;
                    if(t<0){
                        t=(t+q);
                    }
            }
        }   
    }
    
    
    

     
int main()
{	char text[]="ABCCDDAEFG";
    char pattern[]="AEF";
    int prime=13;
    rabinKarp(pattern,text,prime);

    return 0;
}
