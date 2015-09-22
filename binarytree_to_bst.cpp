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


void convertutil(struct node *root,vector<int>& v)
{
    if(root==NULL)
        return;
    convertutil(root->left,v);
    v.push_back(root->data);
    convertutil(root->right,v);
}
int i=0;
void putback(struct node *root,vector<int>& v)
{
    if(root==NULL)
        return;
    putback(root->left,v);
    root->data=v[i++];
    putback(root->right,v);
}
void convert(struct node *root)
{
    vector<int> v;
    convertutil(root,v);
    sort(v.begin(),v.end());
    putback(root,v);
}


int main()
{
    struct node *root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    inorder(root);
    cout<<endl;
    convert(root);
    inorder(root);
    cout<<endl;
    return 0;

}


