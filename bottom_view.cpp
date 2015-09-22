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
void bottomprint(struct node *root,int arr[])
{
    queue< pair<struct node *,int > > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<struct node *,int > p = q.front();
        q.pop();
        struct node *w=p.first;
        arr[p.second+2]=w->data;
        if(w->left)
            q.push(make_pair(w->left,p.second-1));
        if(w->right)
            q.push(make_pair(w->right,p.second+1));
    }
}

void bottom(struct node *root)
{
    int arr[30]={0};
    bottomprint(root,arr);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    struct node *root=NULL;
    root=newnode(20);
        root->left = newnode(8);
        root->right = newnode(22);
        root->left->left = newnode(5);
        root->left->right = newnode(3);
        root->right->left = newnode(4);
        root->right->right = newnode(25);
        root->left->right->left = newnode(10);
        root->left->right->right = newnode(14);


    inorder(root);
    cout<<endl;
    bottom(root);

    return 0;

}
