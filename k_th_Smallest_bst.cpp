#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
int l;
struct node *left;
struct node *right;
};

struct node *newnode(int d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->l=0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
void insertrec(struct node *root,int d)
{
    if(root->data > d)
    {
        root->l++;
        if(root->left==NULL)
        {
            root->left=newnode(d);
            return;
        }
        else
        insertrec(root->left,d);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=newnode(d);
            return;
        }
        else
        insertrec(root->right,d);
    }
}
void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->l<<" ";
        inorder(root->right);
    }
}
int kth(struct node *root,int k)
{
    if(root==NULL)
        return 0;
    if(root->l+1==k)
        return root->data;
    else if(root->l < k)
    {
        k=k-(root->l+1);
        return kth(root->right,k);
    }
    else return kth(root->left,k);
}
int main()
{
    struct node *root=newnode(20);
    insertrec(root,8);
    insertrec(root,22);
    insertrec(root,4);
    insertrec(root,12);
    insertrec(root,10);
    insertrec(root,14);
    int i;
    inorder(root);
    cout<<endl;
    for(i=1;i<7;i++)
    {
        int y=kth(root,i);
        cout<<y<<endl;
    }

    cout<<endl<<root->l;

    return 0;
}
