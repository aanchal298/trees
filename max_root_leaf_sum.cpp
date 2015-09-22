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

int msum=0;
void targetleaf(struct node *root,struct node **leaf,int sum)
{
    if(root==NULL)
        return ;
    sum+=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        if(sum>msum)
        {
            msum=sum;
            (*leaf)=root;
        }
    }
    targetleaf(root->left,leaf,sum);
    targetleaf(root->right,leaf,sum);

};
int print(struct node *root,struct node *leaf)
{
    if(root==NULL)
        return 0;
    if(root==leaf)
    {
        cout<<root->data<<" ";
        return 1;
    }
    int l=print(root->left,leaf);
    int r=print(root->right,leaf);
    if(l||r)
    {
        cout<<root->data<<" ";
        return 1;
    }
}
void karobhi(struct node *root)
{
    struct node *leaf=NULL;
    targetleaf(root,&leaf,0);
    print(root,leaf);
}
int main()
{
     struct node *root = NULL;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);

    karobhi(root);
    return 0;

}


