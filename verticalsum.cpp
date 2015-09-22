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

void versum(struct node *root,map<int,vector<int> >& m,int h)
{
    if(root==NULL)
        return;
    m[h].push_back(root->data);
    versum(root->left,m,h-1);
    versum(root->right,m,h+1);

}
int calculate(struct node *root)
{
    if(root==NULL)
        return 0;
    map<int,vector<int > > m;
    map<int,vector<int> > ::iterator it;
    versum(root,m,0);
    int i;
    for(it=m.begin();it!=m.end();it++)
    {
        int s=0;
        for(i=0;i<it->second.size();i++)
            s+=it->second[i];
        cout<<s<<" ";
    }
    cout<<endl;
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left=newNode(6);
    root->right->right = newNode(7);
    inorder(root);
    cout<<endl;
    calculate(root);
    return 0;

}


