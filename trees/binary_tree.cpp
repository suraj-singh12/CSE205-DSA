#include <iostream>
using namespace std;


// whenever we add a new node to tree, it will be the leaf node;
// so it's left and right will be NULL
// so we can do this step here itself, to reduce code
struct node 
{
    node *left = NULL;
    char data;
    node *right = NULL;
};
node *root = NULL;

// traversal of tree recursively with preorder method 
void preorder(node *root)
{
    if(root == NULL)
        return;
    
    // Preorder : NLR
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    
    // Inorder : LNR
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

// NO THIS IS NOT POSTORDER
void postorder(node *root)
{
    if(root == NULL)
        return;
    
    // postorder : LRN
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

int main()
{
    // root node
    node *nd = new node;
    nd->data = 'A';
    root = nd;
    
    // left child of root node
    node *nd2 = new node;
    nd2->data = 'B';
    nd->left = nd2;
    // right child of root node
    node *nd3 = new node;
    nd3->data = 'C';
    nd->right = nd3;

    // right child of node with data 'B'
    node *nd4 = new node;
    nd4->data = 'D';
    nd2->right = nd4;

    // left child of node with data 'C'
    node *nd5 = new node;
    nd5->data = 'E';
    nd3->left = nd5;
    // right child of node with data 'C'
    node *nd6 = new node;
    nd6->data = 'F';
    nd3->right = nd6;

    // left child of node with data 'F'
    node *nd7 = new node;
    nd7->data = 'G';
    nd6->left = nd7;

    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    // postorder(root);
    // cout << "\n";
    
    return 0;
}