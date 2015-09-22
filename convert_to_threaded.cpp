#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *left,*right;
int th;
};

struct node *newnode(int key)
{
    struct node *treenode=(node*)malloc(sizeof(node));
    treenode->data=key;
    treenode->th=0;
    treenode->left=treenode->right=NULL;
    return treenode;
};
struct node *next=NULL;
void makethreads(struct node *root)
{
    if(root)
    {
        makethreads(root->right);
        if(root->right==NULL)
        {
            root->right=next;
            root->th=1;
        }
        next=root;
        makethreads(root->left);
    }
}
struct node *getleftmost(struct node *root)
{
    if(!root)
        return NULL;
    while(root->left)
    {
        root=root->left;
    }
    return root;

};
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    struct node *curr=getleftmost(root);
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        if(curr->th==1)
            curr=curr->right;
        else
            curr=getleftmost(curr->right);
    }
}
int main()
{
    struct node *root=NULL;
    root=newnode(8);
    root->left=newnode(6);
    root->right=newnode(10);
    root->left->left=newnode(4);
    root->left->right=newnode(7);
    root->right->left=newnode(9);
    root->right->right=newnode(11);
    makethreads(root);
    inorder(root);
    return 0;

}




