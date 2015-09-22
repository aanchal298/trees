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


int findlca(struct node *root,int n1,int n2)
{
    if(root==NULL)
        return -1;
    vector<int> path1,path2;
    populate(root,n1,path1);
    populate(root,n2,path2);
    int i=0,j=0;

    for(i=0,j=0;i<path1.size()&&j<path2.size();i++,j++)
    {
        if(path1[i]!=path2[j])
            break;
    }
    return path1[i-1];
}
void print(struct node *root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right!=NULL)
        cout<<root->right->data<<" ";
    if(root->left!=NULL && root->right==NULL)
        cout<<root->left->data<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);

    print(root);
    cout<<endl;
    return 0;

}

