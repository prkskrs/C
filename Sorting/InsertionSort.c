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

void insertionSort(int a[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp=a[i];
        int j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        
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
    insertionSort(a,n);
    end = clock();
    displaySortedList(a,n);
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n",cpu_time_used);
    return 0;
}
