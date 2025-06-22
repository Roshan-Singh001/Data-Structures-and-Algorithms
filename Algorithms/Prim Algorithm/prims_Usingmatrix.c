#include <stdio.h>
#include <limits.h>
#define V 5

void printGraph(int graph[V][V]){
    printf("Edge \tWeight\n");
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] != -1)
            {
                printf("%d - %d \t%d \n",i,j,graph[i][j]);    
            }
        }  
    }
}


int minimum(int key[V], int visited[V]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[V], int graph[V][V]){
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i,graph[i][parent[i]]);
    }
}

void Prim_MST(int graph[V][V]){
    int parent[V];
    int keys[V];
    int visited[V] = {0,0,0,0,0};

    for (int i = 0; i < V; i++) keys[i] = INT_MAX;
    
    keys[0] = 0;
    parent[0] = 0;

    for (int i = 0; i < V-1; i++)
    {
        int min = minimum(keys,visited);
        visited[min] = 1;
        for (int j = 0; j < V; j++)
        {
            if (((graph[min][j] != -1) && visited[j] == 0) && graph[min][j] < keys[j])
            {
                parent[j] = min;
                keys[j] = graph[min][j];
            }
        }
    }
    printMST(parent,graph);
}

int main()
{
    int graph[V][V] = {
        {-1, 310, 500, 510, -1},
        {310, -1, 2900, 1320, -1},
        {500, 2900, -1, 200, 100},
        {510, 1320, 200, -1, 300},
        {-1, -1, 100, 300, -1},
    };
    printf("Graph: \n");
    printGraph(graph);
    printf("\nUsing Prims Algorithm MST: \n");
    Prim_MST(graph);
    return 0;
}
