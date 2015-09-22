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
void serialize(struct node *root,FILE *fp)
{
    if(root==NULL)
    {
        fprintf(fp,"%d ",-1);
        return;
    }
    else
        fprintf(fp,"%d ",root->data);
    serialize(root->left,fp);
    serialize(root->right,fp);
}
void deserialize(struct node *&root,FILE *fp)
{
    int val;
    int n=fscanf(fp,"%d",&val);
    if(n==0||val==-1)
        return;
    cout<<val<<endl;
    root=newNode(val);
    deserialize(root->left,fp);
    deserialize(root->right,fp);
}
int main()
{
    struct node *root1=NULL;
      struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
    FILE *fp=fopen("fileforserialization.txt","w");
    if(fp==NULL)
        cout<<"couldnt find file!!"<<endl;
    else serialize(root,fp);
    fclose(fp);
    FILE *fd=fopen("fileforserialization.txt","r");
    deserialize(root1,fd);
    inorder(root1);
    return 0;

}


