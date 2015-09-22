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


void merge(struct node *root1,struct node *root2)
{
    stack<struct node *> s1,s2;
    struct node *p=root1,*q=root2;
    int i=1,j=1;
    while(1)
    {
        while(p&&i==1)
        {
            s1.push(p);
            p=p->left;
        }
        while(q&&j==1)
        {
            s2.push(q);
            q=q->left;
        }
        if(s1.empty() || s2.empty())
            break;
        p=s1.top();
        q=s2.top();
        if(p->data < q->data)
        {
            cout<<p->data<<" ";
            s1.pop();
            p=p->right;
            i=1;
            j=0;
        }
        else if(q->data < p->data)
        {
            cout<<q->data<<" ";
            s2.pop();
            q=q->right;
            i=0;
            j=1;
        }
    }

    if(!s1.empty())
    {
        p=p->left;
        while(1)
        {
            while(p)
            {
                s1.push(p);
                p=p->left;
            }
            if(s1.empty())
                break;
            p=s1.top();
            s1.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
    else if(!s2.empty())
    {
        q=q->left;
        while(1)
        {
            while(q)
            {
                s1.push(q);
                q=q->left;
            }
            if(s2.empty())
                break;
            q=s2.top();
            s2.pop();
            cout<<q->data<<" ";
            q=q->right;
        }
    }

cout<<endl;
}


int main()
{
    struct node  *root1 = NULL, *root2 = NULL;
    root1 = newNode(8);
    root1->left = newNode(2);
    root1->left->left=newNode(1);
    root1->right = newNode(10);
    root2 = newNode(5);
    root2->left = newNode(3);
    root2->left->left = newNode(0);
    merge(root1, root2);
    return 0;

}



