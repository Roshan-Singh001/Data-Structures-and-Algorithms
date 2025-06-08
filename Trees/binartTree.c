#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}treeNode;

treeNode * createNode(int data){
    treeNode * node = (treeNode*) malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    treeNode * root = (treeNode*) malloc(sizeof(treeNode));
    root->data = 5;
    root->left = NULL;
    root->right = NULL;

    treeNode * rl = createNode(3);
    treeNode * rr = createNode(10);
    treeNode * ll = createNode(4);
    treeNode * lr = createNode(7);

    root->left = rl;
    root->right = rr;

    rl->left = ll;
    rl->right = lr;
    printf("\t%d",root->data);

    /*  5
       / \
      3  10
     / \
    4  7  */
    return 0;
}