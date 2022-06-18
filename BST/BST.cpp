#include <iostream>
using namespace std;

struct node
{
    node *left, *right;
    int data;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool search(node *root, int val)
{
    if (root == NULL)
    return false;
    else 
    if(root->data == val)
    return true;
    else 
    if(val > root->data)
    return search(root->right, val);
    else
    return search(root->left, val);
}

node *insert(node *root, int x)
{
    if (root == NULL)
    return new node(x);
    if (x > root->data)
    root->right = insert(root->right, x);
    else 
    if (x < root->data)
    root->left = insert(root->left, x);
    return root;
}

int main()
{
    node *root = new node(10);
    root->left = new node(5);
    root->right = new node(30);
    root->right->left = new node(25);
    root->right->right = new node(50);
    cout << "Value search Found = " << search(root, -5) << endl;
    root=insert(root,58);
    cout << "Value search Found = " << search(root, 58) << endl;
    return 0;
}