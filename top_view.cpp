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

void printtop(struct node *root)
{
    map<int,vector<int> > m;
    queue<pair<int,struct node *> > q;
    q.push(make_pair(0,root));
    while(!q.empty())
    {
        pair<int,struct node *> p=q.front();
        q.pop();
        struct node *temp=p.second;
        int h=p.first;
        m[h].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(h-1,temp->left));
        if(temp->right)
            q.push(make_pair(h+1,temp->right));
    }
    map<int,vector<int> >::iterator it;
    int i;
    for(it=m.begin();it!=m.end();it++)
    {
        //for(i=0;i<it->second.size();i++)
            cout<<it->second[0]<<" ";
    }
    cout<<endl;
}

int main()
{
    struct node *root = newNode(1);
    root->left =  newNode(2);
        root->right =  newNode(3);
        root->left->right =  newNode(4);
        root->left->right->right =  newNode(5);
        root->left->right->right->right =  newNode(6);
    printtop(root);
    //inorder(root);
    //cout<<endl;
    return 0;

}


