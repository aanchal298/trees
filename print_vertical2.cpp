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
void printver(struct node *root,map<int,vector<int> > &v,int h)
{
    if(root==NULL)
        return;
    v[h].push_back(root->data);
    printver(root->left,v,h-1);
    printver(root->right,v,h+1);

}
void print(struct node *root)
{
    map< int,vector<int> > v;
    int i;
    printver(root,v,0);
    map < int,vector<int> > :: iterator it;

    for(it=v.begin();it!=v.end();it++)
    {
        for(i=0;i<it->second.size();i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    struct node *root=NULL;
    root=newnode(12);
        root->left = newnode(7);
        root->right = newnode(18);
        root->left->left = newnode(4);
        root->left->right = newnode(10);
        root->right->left = newnode(14);
        root->right->right = newnode(20);
        inorder(root);
    cout<<endl;
        print(root);

    return 0;

}
