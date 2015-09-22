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

int findindex(int arr[],int s,int e,int x)
{
    int j;
    for(j=s;j<=e;j++)
    {
        if(arr[j]==x)
            return j;
    }
    return 0;
}

int i=0;
struct node *construct(int pre[],int post[],int pb,int pe,int n)
{
    if(pb>pe || i>=n)
        return NULL;
    struct node *root=newNode(pre[i]);
    i++;
    if(pb==pe)
        return root;
    int index=findindex(post,0,n-1,pre[i]);
    root->left=construct(pre,post,pb,index,n);
    root->right=construct(pre,post,index+1,pe-1,n);
    return root;
};

int main()
{
   int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = construct(pre, post, 0,size-1,size);
    inorder(root);
    cout<<endl;
    return 0;

}

