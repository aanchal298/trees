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
void swap(int *a,int *b)
{
    int temp= *a;
    *a= *b;
    *b=temp;
}

void correctutil(struct node *root,struct node **first,struct node **second,struct node **last,struct node **prev)
{
    if(root==NULL)
        return;
    correctutil(root->left,first,second,last,prev);
    if((*prev)!=NULL && root->data  < (*prev)->data)
    {
        if((*first)==NULL)
        {
            (*first)=(*prev);
            (*second)=root;
        }
        else
            (*last)=root;
    }
    (*prev)=root;
    correctutil(root->right,first,second,last,prev);
}
void correct(struct node *root)
{
    if(root==NULL)
        return;
    struct node *first=NULL,*second=NULL,*last=NULL,*prev=NULL;
    correctutil(root,&first,&second,&last,&prev);

    if(last==NULL)
        swap(&(first->data),&(second->data));
    else
        swap(&(first->data),&(last->data));
}

int main()
{
   struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);


     inorder(root);
     cout<<endl;
   correct(root);
   inorder(root);
    cout<<endl;

    return 0;

}

