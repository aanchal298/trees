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
int populate(struct node *root,int n1,vector<int> &path)
{
    if(root==NULL)
        return 0;
    path.push_back(root->data);
    if(root->data==n1)
        return 1;
    if(root->left&&populate(root->left,n1,path)!=0 || root->right&&populate(root->right,n1,path)!=0 )
        return 1;

    path.pop_back();
    return 0;
}

int v1=0,v2=0;
int mindis(struct node *root,int n1,int n2,int level)
{
    if(root==NULL)
        return -1;
    if(root->data==n1 || root->data==n2)
    {
        return level;
    }
    int l=mindis(root->left,n1,n2,level+1);
    int r=mindis(root->right,n1,n2,level+1);
    if(l!=-1&&r!=-1)
        return (l+r-(2*level));
    if(l!=-1)
        return l;
    if(r!=-1)
        return r;
}


int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    inorder(root);
    cout<<endl;
    int m=mindis(root,5,8,0);
    cout<<m<<endl;
    return 0;

}

