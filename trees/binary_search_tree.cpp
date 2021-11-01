#include <iostream>
using namespace std;

struct node
{
    node *left = NULL;
    char data;
    node *right = NULL;
};
node *root = NULL;

node *loc = NULL, *par = NULL;  // since we can't return two values from find(), 
// so we keep two global ptr, and update them rather
void find(char item)
{
    node *ptr= root, *save = NULL;
    while(ptr != NULL)
    {
        if(item < ptr->data)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else if(item > ptr->data)
        {
            save = ptr;
            ptr = ptr->right;
        }
        else
        {
            loc = ptr;
            par = save;
            break;
        }
    }
    if(ptr == NULL)
    {
        par = save;
        loc = NULL;
    }
}

void insert(char item)
{
    find(item);
    if(loc!=NULL)
    {
        cout << "Error, element already exists!!\n";
        cout << "Not inserting..\n";
        return;
    }
    else
    {
        node *nd = new node;
        nd->data = item;

        if(par == NULL)
        {
            root = nd;
        }
        else if(item < par->data)
        {
            par->left = nd;
        }
        else
        {
            par->right = nd;
        }
    }
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    
    // inorder traversal
    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

int main()
{
    int n; 
    cout << "Enter the number of nodes you want to insert: ";
    cin >> n;
    while(n > 0)
    {
        cout << "Enter data: ";
        char ch;
        cin >> ch;
        insert(ch);
        n--;
    }
    inorder(root);
    return 0;
}