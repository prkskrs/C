#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

    int b[10];

void merge(int a[],int left,int mid,int right){
    int i=left;
    int j=mid+1;
    int k=left;
    while (i<=mid&&j<=right)
    {
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while (j<=right)
        {
            b[k]=a[j];
            k++;
            j++;
        }
        
    }
    else{
        while (i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
        
    }
    for ( k = left; k <=right; k++)
    {
        a[k]=b[k];
    }
    

}

void mergeSort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void display(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
    
}




int main()
{	int n;
    clock_t start, end;
    double cpu_time_used;
    
    scanf("%d",&n);
    int a[n];
    printf("------enter array values------\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    start = clock();
    mergeSort(a,0,n-1);
    end = clock();
    
    printf("-------------Sorted Array-------------\n");
    display(a,n);
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n",cpu_time_used);
    return 0;
}


     
     
