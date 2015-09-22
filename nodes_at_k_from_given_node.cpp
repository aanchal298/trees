
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

void printdown(struct node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printdown(root->left,k-1);
    printdown(root->right,k-1);
}

int printanc(struct node *root,struct node *target,int k)
{
    if(root==NULL)
        return -1;
    if(root==target)
    {
        printdown(root,k);
        return 0;
    }
    int l=printanc(root->left,target,k);
    if(l!=-1)
    {
        if(l+1==k)
            cout<<root->data<<" ";
        else
            printdown(root->right,k-l-2);
        return l+1;
    }
int     r=printanc(root->right,target,k);
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


    printanc(root,root->left,3);

    return 0;

}
