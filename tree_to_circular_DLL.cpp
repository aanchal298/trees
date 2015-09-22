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

void convertutil(struct node *root,struct node **head,struct node **tail)
{
    if(root==NULL)
        return;
    convertutil(root->left,head,tail);
    struct node *temp=root->right;
    if((*head)==NULL)
    {
        (*head)=(*tail)=root;
        (*tail)->right=root;
        (*head)->left=(*tail);
    }
    else
    {
        (*tail)->right=root;
        root->left=(*tail);
        root->right=(*head);
        (*tail)=root;
        (*head)->left=(*tail);
    }
    convertutil(temp,head,tail);
};
void printlist(struct node *head,struct node *tail)
{
    struct node *p=head;
    while(p->right!=head)
    {
        cout<<p->data<<" ";
        p=p->right;
    }
    cout<<tail->data;
    cout<<endl;
}
int main()
{
   struct node *root = newNode(8);
    root->left        = newNode(4);
    root->right       = newNode(10);
    root->left->left  = newNode(2);
    root->left->right = newNode(6);
    root->left->right->left=newNode(5);
    root->left->right->right=newNode(7);
    inorder(root);
    cout<<endl;
    struct node *head=NULL,*tail=NULL;
    convertutil(root,&head,&tail);
    printlist(head,tail);
    return 0;

}



