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
int height=100;
void findheight(struct node *root,int h)
{
    if(root==NULL)
        return;
    if(root->right==NULL && root->left==NULL)
    {
        if(h<height)
            height=h;
    }
    findheight(root->left,h+1);
    findheight(root->left,h+1);

}

int ishbl(struct node *root,int h)
{
    if(root==NULL)
        return 1;
    if(root->left==NULL && root->left==NULL)
    {
        if(h > 2*height)
            return 0;
        else return 1;
    }
    ishbl(root->left,h+1);
    ishbl(root->right,h+1);

}

int main()
{
    struct node *root=NULL;

        root=newnode(10);
      //  root->left = newnode(5);
    root->right = newnode(100);
    root->right->left = newnode(50);
   // root->right->right = newnode(150);
   // root->right->left->left = newnode(40);

    inorder(root);
    cout<<endl;
    findheight(root,0);
    int i=ishbl(root,0);
    cout<<i<<endl;
    return 0;

}
