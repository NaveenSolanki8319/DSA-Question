#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inOrder(node *root)
{
    if(root==NULL)
        return;
    else
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
f
void preOrder(node *root)       
{
    if(root==NULL)
        return;
    else
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)      
{
    if(root==NULL)
        return;
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

void levelOrder(node *root)     //level order traversal
{
    if(root==NULL)
        return;
    else
    {
        queue <node*>q;
        q.push(root);
        while(!q.empty())
        {
            node *curr =q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right !=NULL)
                q.push(curr->right );
        } 
    }
}

int countNode(node *root)   //count nodes in binry tree
{
    if(root==NULL)
    return 0;
    else
    return(1+countNode(root->left)+countNode(root->right));
}  

int height(node *root) //height of binary tree
{
    if(root==NULL)
    return 0;
    else
    return (1+max(height(root->left),height(root->right)));
} 

int getMax(node *root) //Maximum value of node binary tree
{
    if(root==NULL)
    return 0;
    else
    return max(root->data,max(getMax(root->left) , getMax(root->right)));
}

void printLeftView(node* root)
{
    if (root==NULL)
    return;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {    
        int n = q.size();
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            node* temp = q.front();
            q.pop();
                 
            if (i == 1) // Print the left most element at the level
            cout<<temp->data<<" ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
} 

void printRightView(node* root)
{
    if (root == NULL)
    return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) 
    {
        int n = q.size();
        for(int i = 1; i <= n; i++)  // traverse all the nodes of the current level
        {
            node* x = q.front();
            q.pop();
            if (i == n)     // print the last node of each level
            cout << x->data << " ";
            if (x->left)
            q.push(x->left);
            if (x->right)
            q.push(x->right);
        }
    }
}

// node *lca (node *root, int n1, int n2)
// {
//     if(root==NULL)
//     return NULL;
//     if(root->data==n1 || root->data==n2)
//     return root;
    
//     node *lca1=lca(root->left,n1,n2);
//     node *lca2=lca(root->right,n1,n2);
    
//     if(lca1!=NULL &&lca2!=NULL)
//     return root;
//     if(lca1!=NULL)
//     return lca1;
//     else
//     return lca2;
// }

void leafNodes(node *root)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    cout<<root->data<<" ";
    leafNodes(root->left);
    leafNodes(root->right);
}

bool isMirror(node* root1, node* root2)
{
    // If both trees are empty then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
  
    // For two trees to be mirror images, the following three conditions must be true 
    // 1 - Their root node's key must be same 
    // 2 - left subtree of left tree and right subtree of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree of right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data)
    return (isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left));
   
    // if none of above conditions is true then root1 and root2 are not mirror images
    return false;
}

void serelize(node *root, vector<int> &arr)     //serelization is a method to convert binary tree into string or array form
{
    if(root==NULL)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serelize(root->left,arr);
    serelize(root->right,arr);
}

// node *deSerialize(vector<int> &arr, int &index)     //Deserelization is a method to convert string or array into binary tree 
// {
//     if(index==arr.size())
//     return NULL;
//     int val=arr[index];
//     index++;
//     if(val==-1)
//     return NULL;
//     node *root=new node(val);
//     root->left=deSerialize(arr,index);
//     root->right=deSerialize(arr,index);
//     return root;
// }


int main()
{
    node *root=new node(10);
    root->left=new node(30);
    root->right=new node(20);
    root->right->left=new node(50);
    root->right->right=new node(40);
   
    node *root1=new node(10);
    root1->left=new node(20);
    root1->right=new node(30);
    root1->left->left=new node(40);
    root1->left->right=new node(50);
    
    cout<<"Inorder Traversal "<<endl;
    inOrder(root);
    cout<<endl;
    
    cout<<"Preorder Traversal "<<endl;
    preOrder(root);
    cout<<endl;
    
    cout<<"Postorder Traversal "<<endl;
    postOrder(root);
    cout<<endl;

    cout<<"Level Order Traversal "<<endl;
    levelOrder(root);
    
    cout<<"Nodes in binary tree = "<<countNode(root)<<endl;
    cout<<"Maximum Value = "<<getMax(root)<<endl;
    cout<<"Height = "<<height(root)<<endl;


    cout<<"Left View =";
    printLeftView(root);

    cout<<"\nRight View =";
    printRightView(root);

    cout<<"\nLeaf Nodes = ";
    leafNodes(root);

    cout<<"\nTree is Mirror image or not = ";
    bool ans=isMirror(root,root1);
    cout<<ans<<endl;

    cout<<"\nSerelization of binary tree :- "<<endl;
    vector<int> arr;
	serelize(root,arr);
	for (int x : arr) 
    {
	    cout<<x<<" ";
    }

    // cout<<"\n\nDeserelization of binary tree :- "<<endl;
    // int index=0;
	// node *root_new=deSerialize(arr,index);
	// levelOrder(root_new);

    return 0;
}