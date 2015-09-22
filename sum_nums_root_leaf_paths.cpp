#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int n)
{
    struct node *tem=(node*)malloc(sizeof(node));
    tem->data=n;
    tem->left=NULL;
    tem->right=NULL;
    return tem;
};
void insertrec(struct node *root,int n)
{
    struct node *temp;
    temp=newNode(n);
    if(root==NULL)
    {
        root=temp;
        return;
    }
    if(root->data > n)
    {
        if(root->left==NULL)
        {
            root->left=temp;
            return;
        }
        insertrec(root->left,n);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=temp;
            return;
        }
        insertrec(root->right,n);
    }
}
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(struct node *root)
{
    if(root==NULL)
        return;
    struct node *temp=root;
    queue<struct node *> q;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        if(!q.empty())
        {
            temp=q.front();
            q.pop();
        }
        else break;
    }
    cout<<endl;
}

int sum=0;
void fun(struct node *root,int val)
{
    if(root==NULL)
        return;
        cout<<val<<root->data<<endl;
    val= (val*10)+root->data;
    if(root->left==NULL && root->right==NULL )
    {
        sum+=val;
        return;
    }
    fun(root->left,val);
    fun(root->right,val);
}
int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->right->right= newNode(4);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
   // root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    inorder(root);
    cout<<endl;

    fun(root,0);
    cout<<sum<<endl;
    return 0;

}
