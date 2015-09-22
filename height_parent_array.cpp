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
void finddepth(int arr[],int d[],int i)
{
    if(d[i]!=0)
        return;
    if(arr[i]==-1)
    {
        d[arr[i]]=1;
    }
    if(d[arr[i]]==0)
        finddepth(arr,d,arr[i]);
    d[i]=d[arr[i]]+1;
}
int findheight(int arr[],int n)
{
    int d[10]={0};
    for(int i=0;i<n;i++)
        finddepth(arr,d,i);
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]>m)
            m=d[i];
    }
    return m;

}


int main()
{
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};

    int n = sizeof(parent)/sizeof(parent[0]);
    cout << "Height is " << findheight(parent, n);
    return 0;

}



