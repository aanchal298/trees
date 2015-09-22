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
int level(struct node *root,struct node *ptr,int ll)
{
    if(root==NULL)
        return 0;
    if(root==ptr)
        return ll;
    int l=level(root->left,ptr,ll+1);
    if(l!=0)
        return l;
    else return level(root->right,ptr,ll+1);
}
int issibling(struct node *root,struct node *p1,struct node *p2)
{
    if(root==NULL)
        return 0;
    if(root->left==p1&&root->right==p2 || root->left==p2&&root->right==p1)
        return 1;
    int l=issibling(root->left,p1,p2);
    if(l!=0)
        return l;
    else return issibling(root->right,p1,p2);
}
int iscousin(struct node *root,struct node *p1,struct node *p2)
{
    if(root==NULL)
        return 0;
    int i=level(root,p1,0);
    int j=level(root,p2,0);
    if(i==j)
    {
        int y=issibling(root,p1,p2);
        if(y==0)
            return 1;
        else return 0;
    }
    else return 0;
}
int main()
{
    struct node *root=NULL;
    root=newnode(10);
    insertrec(root,8);
    insertrec(root,12);
    insertrec(root,7);
    insertrec(root,9);
    insertrec(root,11);
    insertrec(root,13);

    inorder(root);
    cout<<endl;
    int y=iscousin(root,root->right->left,root->left->right);
    cout<<y<<endl;
    return 0;

}
