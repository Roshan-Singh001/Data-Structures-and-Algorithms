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

void inOrder(Tree * root){
    stack <Tree *> s1;
    Tree * current = root;
    cout<<"Inorder Traversal: "<<endl;

    while (current != NULL || !s1.empty())
    {
        while (current != NULL)
        {
            s1.push(current);
            current = current->left;
        }
        cout<<(s1.top())->data<<" ";
        current = s1.top();
        s1.pop();

        current = current->right;   
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

    inOrder(root); // 10 17 15 25 20


    /*  20
       / \
     15  25
     / \
    10  17  */
    return 0;
}