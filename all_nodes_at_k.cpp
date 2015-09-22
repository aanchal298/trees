#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *newnode(int data)
{
    struct node *n=(node*)malloc(sizeof(node));
    n->data=data;
    n->left=n->right=NULL;
};

void printdown(struct node *root,int k)
{
    if(root==NULL || k<0)
        return;
    if(k==0)
        cout<<root->data<<" ";
    printdown(root->left,k-1);
    printdown(root->right,k-1);

}

int printkdist(struct node *root,struct node *x,int k)
{
    if(root==NULL || k < 0)
        return -1;
    if(root==x)
    {
        printdown(root,k);
        return 0;
    }
    int l=printkdist(root->left,x,k);
    if(l!=-1)
    {
        if(l+1==k)
            cout<<root->data<<" ";
        else
            printdown(root->right,k-l-2);
        return l+1;
    }
    int r=printkdist(root->right,x,k);
    if(r!=-1)
    {
        if(r+1==k)
            cout<<root->data<<" ";
        else
            printdown(root->left,k-r-2);
        return r+1;
    }
    return -1;
}

int main()
{
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printkdist(root, target, 2);
    return 0;
}


