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
int sum=0;
void leaf(struct node *root)
{
    if(root==NULL)
    return;
    if(root->left)
    {
        if(root->left->left==NULL && root->left->right==NULL)
        {
            sum+=root->left->data;
        cout<<root->left->data<<endl;
        }
    }
    leaf(root->left);
    leaf(root->right);
}

int main()
{
    struct node *root=NULL;
    root=newnode(20);
    insertrec(root,9);
    root->left->left=newnode(5);
    root->left->right=newnode(12);
    root->left->right->right=newnode(15);
    root->right=newnode(49);
    root->right->left=newnode(25);
    root->right->right=newnode(52);
    root->right->right->left=newnode(50);
    inorder(root);
    cout<<endl;
  //  deleten(root,root->right->right);
    //deleten(root,root->right->left);
    leaf(root);
    cout<<sum<<endl;
    return 0;

}
