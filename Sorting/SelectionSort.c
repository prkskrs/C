#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void readArray(int a[],int n)
{
    printf("--------Enter Values In Your Array--------\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
}

void swap(int a[],int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void selectionSort(int a[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j = i+1; j <n; j++)
        {
           if(a[j]<a[min])
           {
               min=j;
           }
        }
        if(min!=i)
        {
            swap(a,min,i);
        }
        
    }
    
}










void displaySortedList(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    
}





int main()
{	clock_t start, end;
    double cpu_time_used;
    
    int n;
    printf("Enter Array Size:");
    scanf("%d",&n);
    int a[n];
    readArray(a,n);
    start = clock();
    selectionSort(a,n);
    end = clock();
    displaySortedList(a,n);
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n",cpu_time_used);
    return 0;
}
