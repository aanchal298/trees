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

void print(struct node *root,int l,int h)
{
    if(root==NULL)
        return ;
    struct node *dinku=NULL;
    queue<pair<int,struct node *> > q;
    q.push(make_pair(1,root));
    q.push(make_pair(0,dinku));
    while(!q.empty())
    {
        pair< int,struct node * > p;
        p=q.front();
        q.pop();
        int i=p.first;
        struct node *temp=p.second;
        if(i>=l && i<=h)
            cout<<temp->data<<" ";
        if(temp==NULL)
            q.push(make_pair(0,dinku));
        else
        {
            if(temp->left)
                q.push(make_pair(i+1,temp->left));
            if(temp->right)
                q.push(make_pair(i+1,temp->right));

        }
    }
    cout<<endl;
}
int main()
{
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    cout << "Level Order traversal between given two levels is";
    print(root, 2, 3);

    return 0;

}


