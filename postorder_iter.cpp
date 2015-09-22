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
struct node *prev=NULL;
void convert(struct node *root,struct node **head)
{
    if(root==NULL)
        return;
    convert(root->left,head);
    if(prev==NULL)
    {
        (*head)=root;
    }
    else
    {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    convert(root->right,head);
}



void printList(struct node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}
struct node * remove(struct node *root,int min,int max)
{
    if(root==NULL)
        return NULL;
    root->left=remove(root->left,min,max);
    root->right=remove(root->right,min,max);
    if(root->data < min)
    {
        struct node *r=root->right;
        free(root);
        return r;
    }
    if(root->data> max)
    {
        struct node *l=root->left;
        free(root);
        return l;
    }
    return root;
};

void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void postiter(struct node *root)
{
    if(root==NULL)
        return ;
    stack<struct node *> s;
    do{
        while(root)
        {
            if(root->right)
                s.push(root->right);
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        if(s.empty())
        {
            cout<<root->data<<" ";
            break;
        }
        if(root->right && s.top()==root->right)
        {
            s.pop();
            s.push(root);
            root=root->right;
        }
        else
        {
            cout<<root->data<<" ";
            root=NULL;
        }

    }while(!s.empty());
    cout<<endl;
}
int main()
{
   struct node* root = NULL;
       root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

     postorder(root);
     cout<<endl;
    postiter(root);
    return 0;

}


