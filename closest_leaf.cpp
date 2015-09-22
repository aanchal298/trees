#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int n)
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

int closestdown(struct node *root)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return (min(closestdown(root->left),closestdown(root->right))+1);
}
int getmin(int a,int b)
{
    if(a<b)
        return a ;
    else return b;
}
int closestutil(struct node *root,struct node *ancestors[],int k,int index)
{
    if(root==NULL)
        return INT_MAX;
    if(root->data==k)
    {
        int res=closestdown(root);
        int i;
        for(i=0;i<index;i++)
        {
            res=getmin(res,index-i+closestdown(ancestors[i]));
        }
        return res;
    }
    ancestors[index]=root;
    return min(closestutil(root->left,ancestors,k,index+1),
    closestutil(root->right,ancestors,k,index+1));

}
int closest(struct node *root,int k)
{
    struct node *ancestors[20]={NULL};
    return closestutil(root,ancestors,k,0);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->left->left = newNode(5);
    root->right->left->left->left = newNode(6);
    root->right->left->left->right = newNode(7);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->right->left = newNode(10);

    inorder(root);
    cout<<endl;
    for(int i=1;i<11;i++)
    {
        int j=closest(root,i);
        cout<<i<<" "<<j<<endl;
    }
    return 0;

}



