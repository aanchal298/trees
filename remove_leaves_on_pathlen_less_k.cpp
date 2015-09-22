
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
struct node *minval(struct node *root)
{
    struct node *p=root;
    while(p->left!=NULL)
        p=p->left;
    return p;
};
struct node *inordersucc(struct node *root,struct node *n)
{
    if(n->right!=NULL)
        return minval(n->right);
    else
    {
        struct node *p=root,*succ=NULL;
        while(p!=NULL)
        {
            if(p->data > n->data)
            {
                succ=p;
                p=p->left;
            }
            else if(p->data < n->data)
               p=p->right;
            else break;
        }
        return succ;
    }
};
void deleten(struct node *root,struct node *nd)
{
    if(nd->left==NULL && nd->right==NULL)
    {
        struct node *p=root;
        while(1)
        {
            if(p->right==nd)
                break;
            if(p->left==nd)
                break;
            if(p->data > nd->data)
                p=p->left;
            else p=p->right;
        }
        if(p->left==nd)
            p->left=NULL;
        if(p->right==nd)
            p->right=NULL;
        free(nd);
        return;
    }
    else if(nd->left!=NULL && nd->right==NULL || nd->left==NULL && nd->right!=NULL)
    {

        struct node *p=root;
        while(1)
        {
            if(p->right==nd)
                break;
            if(p->left==nd)
                break;
            if(p->data > nd->data)
                p=p->left;
            else p=p->right;
        }
        if(p->left==nd)
        {
            if(nd->left!=NULL)
                p->left=nd->left;
            else
                p->left=nd->right;
        }
        else
        {
            if(nd->left!=NULL)
                p->right=nd->left;
            else
                p->right=nd->right;

        }
        free(nd);
        return ;
    }
    else
    {
       struct node *pp=inordersucc(root,nd);
       cout<<pp->data<<endl;
       nd->data=pp->data;
       deleten(root,pp);

    }
}

int remove(struct node *root,int len,int k)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
    {
        if(len>=k)
            return 1;
        else
        {
            root->data=0;
            return 0;

        }
    }
    int l=remove(root->left,len+1,k);
    int r=remove(root->right,len+1,k);
    if(l==0 && r==0)
    {
        root->data=0;
        return 0;
    }
    else return 1;
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
    insertrec(root,6);
    insertrec(root,15);



    inorder(root);
    cout<<endl;
  //  deleten(root,root->right->right);
    //deleten(root,root->right->left);
    remove(root,0,3);
    inorder(root);
    cout<<endl;
    return 0;

}
