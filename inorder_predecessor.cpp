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
int minval(struct node *root)
{
    struct node *p=root;
    while(p->left!=NULL)
        p=p->left;
    return p->data;
}
int inorderpre(struct node *root,struct node *p)
{
    if(p->left!=NULL)
        return minval(p->left);
    else
    {
        struct node *q=root,*pre;
        while(q)
        {
            if(q->data < p->data)
            {
                pre=q;
                q=q->right;
            }
            if(q==p)
                break;
            else q=q->left;
        }
        return pre->data;
    }
}
int main()
{
    struct node *root=NULL;
    root=newnode(20);
        root->left = newnode(8);
        root->right = newnode(22);
        root->left->left = newnode(4);
       root->left->right = newnode(12);
        //root->right->left = newnode(4);
        //root->right->right = newnode(25);
       // root->left->right->left = newnode(10);
        root->left->right->right = newnode(14);


    inorder(root);
    cout<<endl;
    int o=inorderpre(root,root->left);
    cout<<o<<endl;
    return 0;

}

