#include<bits/stdc++.h>
using namespace std;

struct node {
    char data;
    int eostring;
    struct node *left,*right,*eq;
};

struct node *newnode(char d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    temp->eostring=0;
    temp->left=temp->right=temp->eq=NULL;
    return temp;
};

void insert(struct node **root,char *key)
{
    char t=*(key);
    if((*root)==NULL)
    {
        (*root)=newnode(t);
    }
    if((*root)->data > t)
        insert(&((*root)->left),key);
    else if((*root)->data < t)
        insert(&((*root)->right),key);
    else
    {
        if(*(key+1)!=NULL)
            insert(&((*root)->eq),key+1);
        else
            (*root)->eostring=1;
    }
}
int search(struct node *root,char *key)
{
    if(root==NULL )
        return 0;
    if(root->data > *(key))
        return search(root->left,key);
    if(root->data < *key)
        return search(root->right,key);
    else
    {
        if(*(key+1) == NULL)
            return root->eostring;
        else return search(root->eq,key+1);
    }

}
void printstr(char arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;
}
void traverseutil(struct node *root,char buff[],int pathlen)
{
    if(root==NULL)
        return;
    buff[pathlen++]=root->data;
    if(root->eostring==1)
    {
        printstr(buff,pathlen);
    }
    traverseutil(root->eq,buff,pathlen);
    pathlen=0;
    traverseutil(root->left,buff,pathlen);
    traverseutil(root->right,buff,pathlen);

}
void traverse(struct node *root)
{
    if(root==NULL)
        return;
    char buff[20];
    traverseutil(root,buff,0);
}
int main()
{
    struct node *root=NULL;

    insert(&root, "cat");
    insert(&root, "cats");
    insert(&root, "up");
    insert(&root, "bug");

    traverse(root);
//    cout<<y<<endl;
}
