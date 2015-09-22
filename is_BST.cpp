#include<bits/stdc++.h>
using namespace std;
struct node
{
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

int isBST(struct node *root,int min,int max)
{
    if(root==NULL )
        return 1;
    if(root->data < min || root->data > max)
        return 0;
    return(isBST(root->left,min,root->data-1)&&isBST(root->right,root->data+1,max));
}
struct node *prev=NULL;

int bst2(struct node *root)
{
    if(root==NULL)
        return 1;
    if(bst2(root->left)!=1)
        return 0;
    if(prev && root->data < prev->data )
    {
        cout<<root->data<<" "<<prev->data<<endl;
        return 0;
    }
    prev=root;
    return bst2(root->right);
}
int main()
{
    struct node *root = newNode(8);
    root->left        = newNode(4);
    root->right       = newNode(10);
    root->left->left  = newNode(2);
    root->left->right = newNode(6);
    root->left->right->left=newNode(5);
    root->left->right->right=newNode(7);

    if(bst2(root))
        printf("Is BST");
    else
        printf("Not a BST");
    return 0;

}



