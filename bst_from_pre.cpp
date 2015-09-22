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

void morris(struct node *root)
{
    if(root==NULL)
        return;
    struct node *curr=root,*purr;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
             cout<<curr->data;
             curr=curr->right;
        }
        else
        {
            purr=curr->left;
            while(purr->right!=NULL && purr->right!=curr)
                purr=purr->right;
            if(purr->right==NULL)
            {
                purr->right=curr;
                curr=curr->left;
            }
            else
            {
                purr->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }

    }
}
int findno(int arr[],int s,int e,int x)
{
    int i;
    for(i=s;i<=e;i++)
    {
        if(arr[i]>x)
            return i;
    }
    return -1;
}

struct node *construct(int pre[],int s,int e,int n)
{
    if(s>e || s>=n || e>=n)
        return NULL;
    int num=pre[s];
    struct node *root=newNode(num);
    if(s==e)
        return root;
    int index=findno(pre,s+1,e,num);
    cout<<num<<endl;
    root->left=construct(pre,s+1,index-1,n);
    root->right=construct(pre,index,e,n);
    return root;
};
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = construct(pre,0,size-1, size);


inorder(root);
  cout<<endl;
//morris(root);
    return 0;

}

