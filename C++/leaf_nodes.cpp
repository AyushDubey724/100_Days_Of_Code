#include<bits/stdc++.h>
using namespace std;

class node{
    public:

    int data;
    node* left;
    node* right;

    node(int d)
    {
        this -> data = d;
        this ->left = NULL;
        this ->right = NULL;
    }
};

void countleaf(node* root,int &cnt)
{
    if(root == NULL)
        return;

    countleaf(root->left,cnt);

    if(root->left == NULL && root -> right == NULL)
        cnt++;

    countleaf(root->right,cnt);

}

node* buildTree(node* root)
{
    int data;
    cin>> data;

    root = new node(data);

    if(root -> data == -1)
        return NULL;


    cout<<"Enter left data for "<<root->data<<": ";
    root->left = buildTree(root->left);

    

    cout<<"Enter right data for "<<root->data<<": ";
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    int c  = 0;
    node* root = NULL;
    cout<<"Enter root data : ";

   root = buildTree(root);
    countleaf(root,c);
    cout<<"Leaf nodes = "<<c;
    return 0;
}