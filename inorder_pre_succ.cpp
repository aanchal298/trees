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

void presuc(struct node *root,struct node*& pre,struct node*& suc,int key)
{
    if(root==NULL)
        return;
    struct node *temp;
    if(root->data==key)
    {
        if(root->left!=NULL)
        {
            temp=root->left;
            while(temp->right)
                temp=temp->right;
            pre=temp;
        }
        if(root->right!=NULL)
        {
            temp=root->right;
            while(temp)
                temp=temp->left;
            suc=temp;

        }
        return;
    }
    if(root->data > key)
    {
        suc=root;
        presuc(root->left,pre,suc,key);
    }
    else
    {
        pre=root;
        presuc(root->right,suc,pre,key);
    }

}

int main()
{
    struct node *root=NULL;
    struct node *pre=NULL,*suc=NULL;
    root=newnode(20);
        root->left = newnode(8);
        root->right = newnode(22);
        root->left->left = newnode(4);
        root->left->right = newnode(12);
     //  root->right->left = newnode(4);
      //  root->right->right = newnode(25);
        root->left->right->left = newnode(10);
        root->left->right->right = newnode(14);


    inorder(root);
    cout<<endl;
    presuc(root,pre,suc,10);
    cout<<pre->data<<" "<<suc->data<<endl;
    //cout<<o<<endl;
    return 0;

}

