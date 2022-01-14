#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}



int partition(int a[],int low ,int high){
    int pivot=a[low];
    int i=low;
    int j=high;
    while (i<j)
    {
        while(a[i]<=pivot){i++;}
        while(a[j]>pivot){j--;}
        if(i<j){
            swap(a,i,j);
        }

    }
    swap(a,j,low);
    return j;
    

}

void quickSort(int a[],int low, int high){
    if(low<high){
        int pivot=partition(a,low,high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);

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
    scanf("%d",&n);
    int a[n];
    printf("------enter array values------\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a,0,n-1);
    printf("-------------Sorted Array-------------\n");
    display(a,n);
    
    return 0;
}
