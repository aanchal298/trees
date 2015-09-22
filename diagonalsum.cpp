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
void diagonal(struct node *root)
{
    queue<struct node *> q;
    struct node *p=root;
    while(p!=NULL)
    {
        q.push(p);
        p=p->right;
    }
    struct node *temp=root->left;
    int sum=0;
    while(!q.empty())
    {
        struct node *jadu=q.front();
        q.pop();
        if(jadu==temp)
        {
            //cout<<jadu->data<<endl;
            cout<<sum<<endl;
            sum=0;
            if(jadu->left)
            temp=jadu->left;

        }
        //cout<<sum<<endl;
        sum+=jadu->data;
        if(jadu->left)
        {
            //cout<<jadu->left->data<<endl;
            q.push(jadu->left);
            if(jadu->left->right)
                q.push(jadu->left->right);
        }
    }
    cout<<sum<<endl;
}

int main()
{
    struct node *root=NULL;
    root=newnode(1);
    root->left = newnode(2);
        root->right = newnode(3);
        root->left->left = newnode(9);
        root->left->right = newnode(6);
        root->right->left = newnode(4);
        root->right->right = newnode(5);
        root->right->left->left = newnode(12);
        root->right->left->right = newnode(7);
        root->left->right->left = newnode(11);
        root->left->left->right = newnode(10);

    inorder(root);
    cout<<endl;
    diagonal(root);
    cout<<endl;
    return 0;

}
