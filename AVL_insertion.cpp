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
int main()
{
   struct node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  preOrder(root);
  cout<<endl;
}
