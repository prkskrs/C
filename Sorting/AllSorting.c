#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int arr[1000],b[1000],n;

void swap(int a[],int i, int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}


void bubbleSort(int a[],int n)
{   int no_swap=0,comp=0;
    for (int i = 0; i < n-1; i++)
    {   bool swapped=false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j+1]<a[j])
            {   comp++;
                swapped=true;
                swap(a,j+1,j);
                no_swap++;
            }
        }
        if(!swapped){break;}
    }
    printf("No of swaps = %d\n",no_swap);
    printf("No of comparisions  = %d\n",comp);
}

void insertionSort(int a[],int n)
{   int no_swap=0,comp=0;
    for (int i = 1; i < n; i++)
    {
        int temp=a[i];
        int j=i-1;
        

        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            comp++;
            j--;
        }
        a[j+1]=temp;
        no_swap++;
        
    }
    printf("No of swaps = %d\n",no_swap);
    printf("No of comparisions  = %d\n",comp);
      
    
}


void selectionSort(int a[],int n)
{   int no_swap=0,comp=0;
  
    for (int i = 0; i < n-1; i++)
    {
        int min=i;

        for (int j = i+1; j <n; j++)
        {
           if(a[j]<a[min])
           {   comp++;
               min=j;
           }
        }
        if(min!=i)
        {   comp++;
            swap(a,min,i);
            no_swap++;
        }
        
    }
    printf("No of swaps = %d\n",no_swap);
    printf("No of comparisions  = %d\n",comp);
    
}


int merge(int a[],int left,int mid,int right,int comp)
{
    int i=left;
    int j=mid+1;
    int k=left;
    
    while (i<=mid&&j<=right)
    {
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
            comp++;
        }
        else{
            b[k]=a[j];
            j++;
            comp++;
        }
        k++;
    }
    if(i>mid){
        comp++;
        while (j<=right)
        {   
            b[k]=a[j];
            k++;
            j++;
        }
        
    }
    else{comp++;
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
    
return comp;
}




void mergeSort(int a[],int left,int right,int comp){
    int no_swap=0,tc=0;
    
    if(left<right){
        comp++;

        
        int mid=(left+right)/2;
        mergeSort(a,left,mid,comp);
        mergeSort(a,mid+1,right,comp);
        merge(a,left,mid,right,comp);
        tc=merge(a,left,mid,right,comp);

    }
    printf("No of swaps = %d\n",no_swap);
    printf("No of comparisions  = %d\n",tc);

    
}


int main()
{
    int ch,no_swap=0,comp=0;
    clock_t start,end;
    double cpu_time_used;
    printf("Enter size of input/array:");
    scanf("%d",&n);



    while(ch!=8)
    {
        printf("1: to generate array of random/ unsorted values\n");
        printf("2: bubble sort\n");
        printf("3: insertion sort\n");
        printf("4: selection sort\n");
        printf("5: merge sirt\n");
        printf("6: exit program\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:for (int i = 0; i < n; i++)
                  {  arr[i]=rand()%1000;
                     printf(" %d \t", arr[i]);
                  }
                  break;

            case 2: start= clock();
                   bubbleSort(arr,n);
                   end = clock();
                   printf("The sorted array is given below\n");
                   for (int i=0; i < n; i++)
                    {
                         printf("%d\t", arr[i]);
                    }
                   printf("\n");
                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                   printf("Time taken: %lf\n",cpu_time_used);
                 break;
            case 3: start= clock();
                   insertionSort(arr,n);
                   end = clock();
                   printf("The sorted array is given below\n");
                   for (int i=0; i < n; i++)
                    {
                         printf("%d\t", arr[i]);
                    }
                   printf("\n");
                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                   printf("Time taken: %lf\n",cpu_time_used);
                 break;
            case 4: start= clock();
                   selectionSort(arr,n);
                   end = clock();
                   printf("The sorted array is given below\n");
                   for (int i=0; i < n; i++)
                    {
                         printf("%d\t", arr[i]);
                    }
                   printf("\n");
                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                   printf("Time taken: %lf\n",cpu_time_used);
                 break;
            case 5: start= clock();
                   int comp=0;
                   mergeSort(arr,0,n-1,comp);
                   end = clock();
                   printf("The sorted array is given below\n");
                   for (int i=0; i < n; i++)
                    {
                         printf("%d\t", arr[i]);
                    }
                   printf("\n");
                   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                   printf("Time taken: %lf\n",cpu_time_used);
                 break;
            
            
            
        




            case 6: exit(0);
                    break;
    
}
    }






    return 0;
}




