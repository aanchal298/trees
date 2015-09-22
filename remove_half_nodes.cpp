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
struct node *removehalf(struct node *root)
{
    if(root==NULL)
        return NULL;
    root->left=removehalf(root->left);
    root->right=removehalf(root->right);
    if(root->left==NULL&&root->right==NULL)
        return root;
    if(root->left==NULL)
    {
        struct node *p=root->right;
        free(root);
        return p;
    }
    if(root->right==NULL)
    {
        struct node *p=root->left;
        free(root);
        return p;
    }
    return root;
};
int p=1;
int kmax;
void revin(struct node *root,int k)
{
    if(root==NULL) return;
    //cout<<k<<endl;
    revin(root->right,k);
    p++;
    if(p==k)
    {
        cout<<root->data<<endl;
        return;
    }
    revin(root->left,k);


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

    inorder(root);
    cout<<endl;
  //  deleten(root,root->right->right);
    //deleten(root,root->right->left);
    revin(root,3);
    //cout<<o<<endl;
    inorder(root);
    cout<<endl;
    return 0;

}
