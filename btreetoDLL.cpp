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
struct node * convertutil(struct node *root)
{
    if(root==NULL)
        return NULL;
    if(root->left)
    {
        struct node *l=convertutil(root->left);
        while(l->right!=NULL)
            l=l->right;
        l->right=root;
        root->left=l;
    }
    if(root->right)
    {
        struct node *r=convertutil(root->right);
        while(r->left!=NULL)
            r=r->left;
        root->right=r;
        r->left=root;
    }
    return root;
};

struct node * convert(struct node *root)
{
    if(root==NULL)
        return NULL;
    root=convertutil(root);
    while(root->left)
        root=root->left;
    return root;
};
void printList(struct node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}
int main()
{
    struct node *head=NULL;
    struct node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
     inorder(root);
     cout<<endl;
    root= convert(root);

    printList(root);
    return 0;

}

