#include<stdio.h>
#define inf 999
#define n 4

void floyd(int graph[n][n])
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }

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
    int graph[n][n]={{0,inf,3,inf},
    {2,0,inf,inf},
    {inf,7,0,1},
    {6,inf,inf,0}};

    floyd(graph);
    manipulated_matrix(graph);
}
