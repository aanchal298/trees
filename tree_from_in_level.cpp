
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
void insert(struct node **root,int num,queue<struct node *>& q)
{
    struct node *temp=newNode(num);
    cout<<q.front()->data<<endl;
    if((*root)==NULL)
        (*root)=temp;
    else
    {
        struct node *p=q.front();
        if(p->left==NULL)
            p->left=temp;
        else if(p->right==NULL)
            p->right=temp;
        if(p->left!=NULL && p->right!=NULL)
            q.pop();

    }
    q.push(temp);
}
int find(int arr[],int s,int e,int x)
{
    for(int i=s;i<=e;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int * extract(int in[],int s,int e,int level[],int n)
{
     int *newlevel = new int[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(find(in,s,e,level[i])!=-1)
        {
            //cout<<"kjfhek"<<endl;
            //cout<<level[i]<<" "<<find(in,level[i],s,e)<<endl;
             newlevel[k++]=level[i];
        }
    }
    return newlevel;
}

struct node *construct(int in[],int level[],int s,int e,int n)
{
    if(s>e ||s >=n || e>=n)
        return NULL;
    struct node *root=newNode(level[0]);
    if(s==e)
        return root;
    int index=find(in,s,e,level[0]);
    //cout<<index<<endl;

    int *lextract=extract(in,s,index-1,level,n);
  //  for(int i=0;i<5;i++) cout<<lextract[i]<<endl;
    int *rextract=extract(in,index+1,e,level,n);
    root->left=construct(in,lextract,s,index-1,n);
    root->right=construct(in,rextract,index+1,e,n);
    delete [] lextract;
    delete [] rextract;
    return root;
};

int main()
{
     struct node *root=NULL;
     queue<struct node *> q;
     int i;
     int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    root=construct(in,level,0,6,7);
    levelorder(root);
    cout<<endl;
    return 0;

}

