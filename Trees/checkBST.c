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
    8  45
  /  \
 7    9  */

 treeNode * createNode(int val){
    treeNode * node = (treeNode*) malloc(sizeof(treeNode)); 
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int isBST(treeNode * root){
    static treeNode * prev = NULL;
    if (root != NULL)
    {
        if (! isBST(root->left)) return 0;
        if (prev != NULL && root->data <= prev->data) return 0;
        prev = root;
        return isBST(root->right);
    }
    else return 1;
}

int main()
{
    treeNode * n = createNode(10);
    treeNode * n1 = createNode(8);
    treeNode * n2 = createNode(45);
    treeNode * n3 = createNode(7);
    treeNode * n4 = createNode(9);

    n->left = n1;
    n->right = n2;

    n1->left = n3;
    n1->right = n4;

    if (isBST(n)) printf("Given Tree is a Binary Search Tree");
    else printf("Given Tree is not a Binary Search Tree");
    return 0;
}
