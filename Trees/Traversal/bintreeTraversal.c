#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}treeNode;

/*   10
    /  \
   11  45
  /  \
 27  98  */

treeNode * createNode(int val){
    treeNode * node = (treeNode*) malloc(sizeof(treeNode)); 
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postorder(treeNode * root){
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(treeNode * root){
    if (root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(treeNode * root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main()
{
    treeNode * n = createNode(10);
    treeNode * n1 = createNode(11);
    treeNode * n2 = createNode(45);
    treeNode * n3 = createNode(27);
    treeNode * n4 = createNode(98);

    n->left = n1;
    n->right = n2;

    n1->left = n3;
    n1->right = n4;
    printf("Postorder: ");
    postorder(n);
    printf("\nPreorder: ");
    preorder(n);
    printf("\nInorder: ");
    inorder(n);
    return 0;
}
