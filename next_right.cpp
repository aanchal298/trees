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
struct node *test(struct node *root,int k)
{
    queue< struct node *> q;
    queue<int> ql;
    q.push(root);
    ql.push(0);
    while(!q.empty())
    {
        struct node *temp=q.front(); q.pop();
        int level=ql.front(); ql.pop();
        if(temp->data==k)
        {
            if(q.empty() || level!=ql.front())
                return NULL;
            else return q.front();
        }

        if(temp->left)
        {
            q.push(temp->left);
            ql.push(level+1);
        }
        if(temp->right)
        {
            q.push(temp->right);
            ql.push(level+1);
        }
    }

};
int main()
{
   int k = 45;
    struct node* root = newNode(10);
     root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    struct node *tofind=NULL;
    tofind=test(root, 4);
    if(tofind!=NULL)
    cout<<tofind->data<<endl;

    //inorder(root);
    cout<<endl;
   ;
    return 0;

}
