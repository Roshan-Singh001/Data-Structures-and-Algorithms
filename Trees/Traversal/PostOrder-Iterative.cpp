#include <iostream>
#include <stack>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

}Tree;

Tree * createNode(int val){
    Tree * node = (Tree*) malloc(sizeof(Tree)); 
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postOrder(Tree * root){
    stack <Tree *> s1;
    stack <Tree *> s2;

    cout<<"Post Order Traversal: "<<endl;

    s1.push(root);

    while (!s1.empty())
    {
        Tree * temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left != NULL) s1.push(temp->left);
        if (temp->right != NULL) s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout<<(s2.top())->data<<" ";
        s2.pop();
    }
}


int main(){
    Tree * root = createNode(20);
    Tree * l = createNode(15);
    Tree * r = createNode(25);
    Tree * ll = createNode(10);
    Tree * lr = createNode(17);

    root->left = l;
    root->right = r;

    l->left = ll;
    l->right = lr;

    postOrder(root); // 10 17 15 25 20


    /*  20
       / \
     15  25
     / \
    10  17  */
    return 0;
}