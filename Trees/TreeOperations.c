#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    struct Tree * left;
    struct Tree * right;
}tree;


/*   10
    /  \
    5  45
  /  \
 4   7  */

tree * createNode(int data){
    tree * node = (tree*) malloc(sizeof(tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Traversal (Inorder)
void inorder(tree * root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

//Searching in BST
int * search(tree * root, int key){
    if (root == NULL)
    {
        printf("\n%d is not found\n",key);
        return 0;
    }
    if (key == root->data)
    {
        printf("\n%d is found\n",key);
        return 0;
    }
    else if (key < root->data) search(root->left,key);
    else search(root->right,key);
}

//Insertion in Binary Search Tree (BST)
void insert(tree * root, int data){
    tree * prev = NULL;
    tree * p = root;
    while (p != NULL)
    {
        prev = p;
        if (data == p->data)
        {
            printf("\n%d is already exists\n",data);
            return;
        }
        else if (data < p->data) p = p->left;
        else p = p->right;
    }
    tree * node = createNode(data);
    if (data < prev->data) prev->left = node;
    else prev->right = node;
}

//Deletion in Binary Search Tree

tree * inOrderPredecessor(tree * root){
    root = root->left;
    while (root->right != NULL) root = root->right;
    return root;
}

tree * delete(tree * root, int data){
    tree * inpre = NULL;
    if (root == NULL){
        printf("\nTree is Empty\n");
        return NULL;
    } 
    //Check fot the leaf node
    if ((root->left == NULL) && (root->right == NULL) && (root->data == data))
    {
        free(root);
        return NULL;
    }
    else if(root->left == NULL && root->right == NULL && root->data != data)
    {
        printf("\n%d is not present in the tree\n",data);
        return root;
    }

    //seaching 
    if (data > root->data) root->right = delete(root->right,data);
    else if (data < root->data) root->left = delete(root->left,data);
    else
    {
        inpre = inOrderPredecessor(root);
        root->data = inpre->data;
        root->left = delete(root->left,inpre->data);
    }
    return root;
}

int main()
{
    tree * n = createNode(10);
    tree * n1 = createNode(5);
    tree * n2 = createNode(45);
    tree * n3 = createNode(4);
    tree * n4 = createNode(7);

    n->left = n1;
    n->right = n2;

    n1->left = n3;
    n1->right = n4;

    insert(n,10);
    printf("\n");
    inorder(n);

    // search(n,1);

    printf("\n");
    delete(n,10);
    inorder(n);
    return 0;
}