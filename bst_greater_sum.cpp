#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int n)
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
    temp=newnode(n);
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
void rev(struct node *root)
{
    if(root)
    {
        rev(root->right);
        sum+=root->data;
        root->data=sum-root->data;
        rev(root->left);
    }
}
int main()
{
    struct node *root=NULL;
    root=newnode(11);
        root->left = newnode(2);
    root->right = newnode(29);
    root->left->left = newnode(1);
    root->left->right =newnode(7);
    root->right->left =newnode(15);
    root->right->right =newnode(40);
    root->right->right->left = newnode(35);

    inorder(root);
    cout<<endl;
    rev(root);
    inorder(root);
    cout<<endl;
    return 0;

}
