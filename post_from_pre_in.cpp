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
int search(int arr[],int x,int s,int e)
{
    for(int i=s;i<=e;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int p=0;
void printpost(int in[],int pre[],int is,int ie,int n)
{
    if(p==6)
        return;
    int root=search(in,pre[p],is,ie);
    //cout<<p<<" "<<root<<endl;
    p++;
    if(is!=ie)
    {
        printpost(in,pre,is,root-1,n);
        printpost(in,pre,root+1,ie,n);
    }

    cout<<in[root]<<" ";
}
int main()
{
    int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
int n=6;
   cout << "Postorder traversal " << endl;
   printpost(in, pre, 0,6,n);
   return 0;
    return 0;

}



