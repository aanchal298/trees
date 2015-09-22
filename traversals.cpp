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
/*
void insert(struct node *root,int n)
{
    struct node *temp,*nn;
    nn=newnode(n);
    if(root==NULL)
    {
        root=nn;
        return;
    }
    else
    {
        queue<struct node *> q;
        q.push(root);
        while(!q.empty())
        {
            struct node *temp=q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            else
            {
                temp->left=nn;
                return;
            }
            if(temp->right)
                q.push(temp->right);
            else
            {
                temp->right=nn;
                return;
            }
        }
    }
}*/
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
int searchrec(struct node *root,int n)
{
    if(root==NULL)
        return 0;
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *temp=q.front();
        q.pop();
        if(temp->data==n)
            return 1;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return 0;
}
int search(struct node *root,int n)
{
    if(root==NULL)
        return 0;
    if(root->data==n)
        return 1;
    if(root->data > n)
        return search(root->left,n);
    else return search(root->right,n);
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
void levelorder(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        struct node *curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

void mirror(struct node *root)
{
    if(root==NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
};

struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newnode(data));
  else
  {
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
  }
}
int minv(struct node *root)
{
    if(root->left==NULL)
        return root->data;
    return minv(root->left);
}

void print(struct node *root,int a,int b)
{
    if(root==NULL)
        return ;
    if(root->data > b)
        print(root->left,a,b);
    if(root->data < a)
        print(root->right,a,b);
    if(root->data > a && root->data < b)
    {
        cout<<root->data<<" ";
        print(root->left,a,b);
        print(root->right,a,b);
    }
}
int path(struct node *root,int sum)
{
    if(root==NULL && sum!=0)
        return 0;
    if(root->left==NULL && root->right==NULL && sum==root->data)
    {
        cout<<root->data<<" ";
        return 1;
    }
    int l=path(root->left,sum-root->data);
    int r=path(root->right,sum-root->data);
    if(l||r)
    {
        cout<<root->data<<" ";
        return 1;
    }
    else return 0;

}

int issumtree(struct node *root)
{
    if(root==NULL)
        return 0;
    int l=issumtree(root->left);
    int r=issumtree(root->right);
    if(root->left==NULL && root->right==NULL)
        return root->data;
    if(l!=-1 && r!=-1)
    {
        if(l+r==root->data)
            return l+r+root->data;
        else return -1;
    }
    return -1;

}
int main()
{
  struct node *root  = newnode(26);
    root->left         = newnode(10);
    root->right        = newnode(3);
    root->left->left   = newnode(4);
    root->left->right  = newnode(6);
    root->right->right = newnode(3);
int y=issumtree(root);
cout<<y<<endl;
  path(root,14);

    return 0;

}
