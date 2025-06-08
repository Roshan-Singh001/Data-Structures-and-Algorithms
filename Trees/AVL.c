#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}avl;

avl * createNode(int data){
    avl * node = (avl*) malloc(sizeof(avl));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getheight(avl * n){
    if (n == NULL) return 0;
    return n->height;
}

int balance_factor(avl * n){
    if (n == NULL) return 0;
    return getheight(n->left) - getheight(n->right);
}

int max(int a, int b){
    return (a > b)? a : b;
}

//Right Rotate
avl * Right_rotate(avl * y){
    avl * x = y->left;
    avl * t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getheight(y->left),getheight(y->right))+1;
    x->height = max(getheight(x->left),getheight(x->right))+1;
    return x;
}

//Left Rotate
avl * Left_rotate(avl * x){
    avl * y = x->right; 
    avl * t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getheight(x->left),getheight(x->right))+1;
    y->height = max(getheight(y->left),getheight(y->right))+1;
    return y;
}

//Insertion
avl * insert(avl * root, int key){
    if (root == NULL) return createNode(key);

    if (root->data < key) root->right = insert(root->right,key);
    else if (root->data > key) root->left = insert(root->left,key);
    else return root;

    root->height = 1 + max(getheight(root->left),getheight(root->right));

    int balance = balance_factor(root);

    //L-L
    if (balance > 1 && key < root->left->data) return Right_rotate(root);
    //R-R
    if (balance < -1 && key > root->right->data) return Left_rotate(root);
    //L-R
    if (balance > 1 && key > root->left->data)
    {
        root->left = Left_rotate(root->left);
        return Right_rotate(root);
    }
    //R-L
    if (balance < -1 && key < root->right->data)
    {
        root->right = Right_rotate(root->right);
        return Left_rotate(root);
    }
    return root;
}

//Travesal(Preorder)
void preorder(avl * root){
    if (root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    avl * root = NULL;
    root = insert(root,7);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,17);
    root = insert(root,16);
    // root = insert(root,4);
    preorder(root);

    return 0;
}