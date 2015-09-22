#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *left;
struct node *right;
};
struct node * newnode(int d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
};


void maketree(struct node *root ,int arr[],int i,int n)
{
    if(i>=n)
        return;
    root->left=newnode(arr[i]);
    maketree(root->left,arr,i+1,n);
    int v=arr[i]*10 + arr[i+1];
    if(v>26)
        root->right=NULL;
    else
    {
        root->right=newnode(v);
        maketree(root->right,arr,i+2,n);
    }
}
void printarr(int arr[],int n)
{
    int i=0;
    for(i=1;i<n;i++)
        cout<<(char)(arr[i]+96)<<" ";
    cout<<endl;
}
void display(struct node *root,int path[],int pathlen)
{
    if(root==NULL)
        return;
    path[pathlen++]=(root->data);
    if(root->right==NULL && root->left==NULL)
    {
        printarr(path,pathlen);
    }
    display(root->left,path,pathlen);
    display(root->right,path,pathlen);

}

int main()
{
    struct node *root=NULL;
    root=newnode(0);
    int arr[]={1,2,2,1};
    maketree(root,arr,0,4);
    int path[20]={0};
    display(root,path,0);
}
