#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;int it;
    struct node *left;
    struct node *right;
};
struct node *newNode(int n)
{
    struct node *tem=(node*)malloc(sizeof(node));
    tem->data=n;
    tem->it=0;
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
struct node *leftMost(struct node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
struct node *n=NULL;
void make(struct node *root)
{
    if(root==NULL)
        return;
    make(root->right);
    if(root->right==NULL)
    {
        root->right=n;
        root->it=1;
    }
    n=root;
    make(root->left);
}
void inordert(struct node *root)
{
    if(root==NULL)
        return;
    struct node *curr=leftMost(root);
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        if(curr->it!=0)
            curr=curr->right;
        else
            curr=leftMost(curr->right);
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout<<endl;
    make(root);
    inordert(root);
    cout<<endl;

    return 0;

}


