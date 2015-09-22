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

int complete(struct node *root)
{
    queue<struct node *> q;
    q.push(root);

        int p=0;
        while(!q.empty())
        {
    //        cout<<"mkl"<<endl;
            struct node *zz=q.front();
            q.pop();
            if(p==0)
            {
                if(zz->right && zz->left)
                {
      //              cout<<"jo"<<endl;
                    q.push(zz->left);
                    q.push(zz->right);
                }
                else if(zz->right==NULL &&zz->left!=NULL)
                {
                    p=1;
                    q.push(zz->left);
                }
                else if(zz->right!=NULL && zz->left==NULL)
                {
                    cout<<zz->data<<endl;
                    return 0;
                }
                else if(zz->right==NULL &&zz->left==NULL)
                    p=1;
            }
            else if(p==1)
            {
                if(zz->left==NULL &&zz->right==NULL)
                    continue;
                else return 0;
            }
        }
        return 1;

}

int main()
{
    struct node *root=NULL;
    root=newnode(10);
    insertrec(root,8);
    //insertrec(root,12);
    insertrec(root,7);
    insertrec(root,9);
    //insertrec(root,11);
    //insertrec(root,13);

    inorder(root);
    cout<<endl;
    int i=complete(root);
    cout<<i<<endl;
    return 0;

}
