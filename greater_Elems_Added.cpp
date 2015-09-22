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


void printList(struct node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}

int c=0;
int ceil(struct node *root,int key)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return key;
    if(root->data < key)
        return ceil(root->right,key);
    else if(root->data > key)
    {
        int l=ceil(root->left,key);
        if(l<root->data && l>= key)
            return l;
        else return root->data;
    }
}
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    stack<struct node *> s;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            s.push(root);
            root=root->left;

        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();

        root=root->right;
    }
}
int sum=0;
void rev(struct node *root)
{
    if(root==NULL)
        return;
    rev(root->right);
    sum+=root->data;
    root->data+=sum-root->data;
    rev(root->left);
}

int main()
{
     struct node *root = newNode(5);
   root->left = newNode(2);
    root->right = newNode(13);
    inorder(root);
  cout<<endl;
  rev(root);
inorder(root);
  cout<<endl;

    return 0;

}

