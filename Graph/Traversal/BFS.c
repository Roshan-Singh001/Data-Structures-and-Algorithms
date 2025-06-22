#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int back;
    int size;
    int *a;
}queue;

void show(queue * q){
    printf("\n");
    for (int i = q->front + 1; i <= q->back; i++)
    {
        printf("%d ",q->a[i]);
    }
    printf("\n");
}

void enqueue(queue * q, int data){
    if (q->back == q->size-1)
    {
        printf("\nOverflow\n");
    }
    else
    {
        q->back++;
        q->a[q->back] = data;
    }
}

int dequeue(queue * q){
    int val = 0;
    if (q->front == q->back)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        val = q->a[q->front + 1];
        q->front++;
    }
    return val;
}

int main()
{
    queue *q;
    q->front = -1;
    q->back = -1;
    q->size = 1000;
    q->a = (int*) malloc(q->size * sizeof(int));

    int node;
    int source = 0;
    int visited[7] = {0,0,0,0,0,0,0};

    //Adjacency Matrix
    int g[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    printf("%d ",source);
    visited[source] = 1;
    enqueue(q,source);

    while (q->front != q->back)
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (g[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ",j);
                visited[j] = 1;
                enqueue(q,j);
            }
        }
    }
    return 0;
}