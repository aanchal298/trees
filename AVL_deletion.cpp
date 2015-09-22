#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
struct node *newNode(int d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->left=temp->right=NULL;
    temp->height=1;
};
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    else return root->height;
}

struct node *rightrotate(struct node *z)
{
    struct node *y=z->left;
    struct node *t2=y->right;

    y->right=z;
    z->left=t2;

    y->height=max(height(y->left),height(y->right))+1;
    z->height=max(height(z->left),height(z->right))+1;
    return y;
};
struct node *leftrotate(struct node *z)
{
    struct node *y=z->right;
    struct node *t2=y->left;

    y->left=z;
    z->right=t2;
    y->height=max(height(y->left),height(y->right))+1;
    z->height=max(height(z->left),height(z->right))+1;
    return y;

};
int getbalance(struct node *root)
{
    if(root==NULL)
        return 0;
    return (height(root->left)-height(root->right));
}
struct node *insert(struct node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    if(root->data > key)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);

    int balance=getbalance(root);
    if(balance>1 && key<root->left->data)
        return rightrotate(root);
    if(balance<1 && key>root->right->data)
        return leftrotate(root);
    if(balance>1 &&key>root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<1 &&key<root->right->data)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
};
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct node *minval(struct node *root)
{
    struct node *p=root;
    while(p->left!=NULL)
        p=p->left;
    return p;
};
struct node * deletenode(struct node *root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data > key)
        root->left=deletenode(root->left,key);
    else if(root->data < key)
        root->right=deletenode(root->right,key);

    else if(root->data==key)
    {
        if(root->left==NULL || root->right==NULL)
        {
            struct node *temp=(root->left)? root->left : root->right;
            if(temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
            {
                root=temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp=minval(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    if(root==NULL)
        return root;
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getbalance(root);
    if(balance>1 && getbalance(root->left)>=0)
        return rightrotate(root);
    if(balance<-1 && getbalance(root->right)<=0)
        return leftrotate(root);
    if(balance>1 && getbalance(root->left)<0)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && getbalance(root->right)>0)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
};



int main()
{struct node *root = NULL;

  /* Constructing tree given in the above figure */
root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  preOrder(root);
  cout<<endl;
  root = deletenode(root, 20);
  preOrder(root);
  cout<<endl;
  return 0;
}
