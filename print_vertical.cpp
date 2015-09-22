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
void printthem(struct node *root,int index,int h)
{
    if(root==NULL)
        return;
    if(index==h)
        cout<<root->data<<" ";
   printthem(root->left,index-1,h);
   printthem(root->right,index+1,h);
}
void findminmaxhor(struct node *root,int& min,int& max,int h)
{
    if(root==NULL)
        return;
    if(h<min) min=h;
    if(h>max) max=h;
    findminmaxhor(root->left,min,max,h-1);
    findminmaxhor(root->right,min,max,h+1);
}
void printvertical(struct node *root)
{
    int min=0,max=0;
    if(root==NULL)
        return;
    findminmaxhor(root,min,max,0);
    for(int i=min;i<=max;i++)
    {
        printthem(root,i,0);
        cout<<endl;
    }
}
int main()
{
    struct node *root=NULL;
    root=newnode(12);
        root->left = newnode(7);
        root->right = newnode(18);
        root->left->left = newnode(4);
        root->left->right = newnode(10);
        root->right->left = newnode(14);
        root->right->right = newnode(20);
        inorder(root);
    cout<<endl;
        printvertical(root);

    return 0;

}
