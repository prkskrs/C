#include<stdio.h>
#define n 4


int max(int num1,int num2)
{
    if(num1>num2)
    return num1;
    else{}
    return num2;
}

void warshall(int graph[n][n])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                graph[i][j]=max(graph[i][j],graph[i][k]&&graph[k][j]);
            }
        }
     }
}


void manipulated_matrix(int graph[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
        
    }
    
}
    


int main()
{
    int graph[n][n]={{0,1,0,0},
    {0,0,0,1},
    {0,0,0,0},
    {1,0,1,0}};

    warshall(graph);
    manipulated_matrix(graph);
}
