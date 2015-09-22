#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *NewNode(int n)
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
    temp=NewNode(n);
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

int pairsum(struct node *root,int sum)
{
    stack<struct node *> s1,s2;
    int v1,v2;
    int done1=1,done2=1;
    struct node *p=root,*q=root;
    while(1)
    {
        if(done1==1)
        {
            while(p)
            {
                s1.push(p);
                p=p->left;
            }
            if(s1.empty())
                break;
            struct node *pp=s1.top();
            s1.pop();
            v1=pp->data;
            p=pp->right;
        }

        if(done2==1)
        {
            while(q)
            {
                s2.push(q);
                q=q->right;
            }
            if(s2.empty())
                break;
            struct node *qq=s2.top();
            s2.pop();
            v2=qq->data;
            q=qq->left;
        }
        cout<<v1<<" "<<v2<<endl;
        if(v1+v2==sum && v1!=v2)
            return 1;
        else if(v1+v2 < sum)
        {
            done1=1;
        }
        else if(v1+v2 > sum)
        {
            done2=1;
        }
        else if(v1>=v2)
            return 0;
    }
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

int isthere(struct node *head,int sum)
{
    struct node *a=head,*b=head;
    while(b->right!=NULL)
        b=b->right;
    while(a->data!=b->data && a!=NULL && b!=NULL)
    {
        if(a->data+b->data == sum)
        {
            cout<<a->data<<" "<<b->data<<" ";
            return 1;
        }
        else if(a->data+b->data <sum && a->data!=b->data)
            a=a->right;
        else
            b=b->left;
    }
    return 0;
}
int isthree(struct node *root,int sum)
{
    if(root==NULL)
        return 0;
    struct node *head=NULL;
    convert(root,&head);
    struct node *p=head;
    while(p!=NULL)
    {
        int t=isthere(head->right,sum-head->data);
        if(t==1)
        {
            cout<<p->data<<endl;
            return 1;
        }
        else p=p->right;
    }
    return 0;
}

int main()
{
    //struct node *head=NULL;
    struct node *root = NewNode(6);

    insertrec(root, -13);
    insertrec(root, 14);
    insertrec(root, -8);
    insertrec(root, 15);
    insertrec(root, 13);
    insertrec(root, 7);
    inorder(root);
    cout<<endl;
    int y=isthree(root,0);
    cout<<y<<endl;
    return 0;

}

