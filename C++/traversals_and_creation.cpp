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
        this -> left = NULL;
        this -> right  = NULL;
    }
};

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

void preorder(node* root)
{
    if(root == NULL)
        return;

    cout<< root -> data <<"  ";
    preorder(root->left);
    preorder(root->right);
}

void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;

            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
 
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)   
                    q.push(temp->right);

        }
    }
}
int main()
{
    node* root  = NULL;
        cout<<"Enter root data : ";
       root = buildTree(root);
       bfs(root);
 

    return 0;
}