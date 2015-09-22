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
struct node *prev=NULL;
void convert(struct node *root,struct node **head)
{
    if(root==NULL)
        return;
    convert(root->left,head);
    if(prev==NULL)
    {
        (*head)=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    convert(root->right,head);
}



void printList(struct node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}
struct node * remove(struct node *root,int min,int max)
{
    if(root==NULL)
        return NULL;
    root->left=remove(root->left,min,max);
    root->right=remove(root->right,min,max);
    if(root->data < min)
    {
        struct node *r=root->right;
        free(root);
        return r;
    }
    if(root->data> max)
    {
        struct node *l=root->left;
        free(root);
        return l;
    }
    return root;
};
int main()
{
    struct node *head=NULL;
    struct node *root = newNode(6);
    insertrec(root,-13);
    insertrec(root,14);
    insertrec(root,-8);
    insertrec(root,15);
    insertrec(root,13);
    insertrec(root,7);

     inorder(root);
     cout<<endl;
    root=remove(root,-10,13);
    inorder(root);
    return 0;

}

