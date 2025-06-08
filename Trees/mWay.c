#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct Node
{
    int numKeys;
    int keys[MAX - 1];
    struct Node *childrens[MAX];
}Node;

Node* createNode(){
    Node* new = (Node*) malloc(sizeof(Node));
    new->numKeys = 0;
    for (int i = 0; i < MAX - 1; i++) new->keys[i] = 0;
    for (int i = 0; i < MAX; i++) new->childrens[i] = NULL;

    return new;
}

void insert(Node *root, int key){
    int i;
    if (root->numKeys < MAX - 1)
    {
        for ( i = root->numKeys - 1; i >= 0 && root->keys[i] > key; i--)
        {
            root->keys[i+1] = root->keys[i];
        }
        root->keys[i+1] = key;
        root->numKeys++;
        
    }
    else
    {
        /* code */
    }
    
    
    
    
}


int main(){

    return 0;
}