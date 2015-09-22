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
int arr[30],i;
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

void storeinorder(struct node *root,int p)
{
    if(root)
    {
        storeinorder(root->left,!p);
        if(p==0)
        arr[i++]=root->data;
        storeinorder(root->right,!p);
    }
}

void putback(struct node *root,int p)
{
    if(root)
    {
        putback(root->left,!p);
        if(p==0)
        root->data=arr[i++];
        putback(root->right,!p);
    }
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
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
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
        root->right->right->left = newnode(1);
        root->right->right->right = newnode(2);

        root->right->left = newnode(29);
        root->right->left->left = newnode(500);
        root->right->left->right = newnode(600);

        root->left->left->left=newnode(100);
        root->left->left->right=newnode(200);

        root->left->right->left = newnode(10);
        root->left->right->right = newnode(14);


    levelorder(root);
    cout<<endl;
    storeinorder(root,1);
    for(int j=0;j<i;j++)
        cout<<arr[j]<<" ";
    cout<<endl;
    for(int j=0;j<i/2;j++)
    {
        //cout<<arr[j]<<" "<<arr[i-j-1]<<endl;
        swap(&arr[j],&arr[i-j-1]);
    }
    for(int j=0;j<i;j++)
        cout<<arr[j]<<" ";
    cout<<endl;
    i=0;
    putback(root,1);
    levelorder(root);

    return 0;

}

