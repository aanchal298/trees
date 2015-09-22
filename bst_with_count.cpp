#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left,*right;
    int c;
};
struct node *newnode(int n)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=n;
    temp->c=1;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
struct node *root=NULL;
void insert(struct node *root,int n)
{
    struct node *p;
    if(root==NULL)
    {
        p=newnode(n);
        root=p;
    }
    if(root->data==n)
    {
        root->c++;
        return;
    }
    if(root->data > n)
    {
        if(root->left==NULL)
        {
            root->left=newnode(n);
            return;
        }
        insert(root->left,n);
    }

    else if(root->data < n)
    {
        if(root->right==NULL)
        {
            root->right=newnode(n);
            return;
        }
         insert(root->right,n);
    }
}
void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<"("<<root->c<<")"<<" ";
        inorder(root->right);
    }
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
struct node * deletenn(struct node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    if(root->data > key)
        return deletenn(root->left,key);
    if(root->data < key)
        return deletenn(root->right,key);
}

void deletekaro(struct node *root,struct node *nd)
{
    if(root->data==nd->data)
    {
        if(root->c!=1)
        {
            root->c--;
            return;
        }
        else
        {
            struct node *succ=inordersucc(root,nd);
            nd->data=succ->data;
            nd->c=succ->c;
            deleten(root,succ);
        }
    }
    else if(root->data > nd->data)
        deletekaro(root->left,nd);
    else deletekaro(root->right,nd);
}

void del(struct node *root,int key)
{
    struct node *pp=deletenn(root,key);
    deletekaro(root,pp);
}

int main()
{
    struct node*root=newnode(12);
    //insert(root,12);
    insert(root,10);
    insert(root,20);
    insert(root,9);
    insert(root,11);
    insert(root,10);
    insert(root,12);
    insert(root,12);
    inorder(root);
    cout<<endl;
    del(root,20);
    inorder(root);
    cout<<endl;

}
