#include<bits/stdc++.h>
using namespace std;
#define n 5
struct node{
    char data;
    struct node *children[n];
};
struct node *newNode(char num)
{
    struct node *tem=(node*)malloc(sizeof(node));
    tem->data=num;
    int i;
    for(i=0;i<n;i++)
        tem->children[i]=NULL;
    return tem;
};


void serialize(struct node *root,FILE *fp)
{
    if(root==NULL)
    {
        return;
    }
    else
       fprintf(fp,"%c ",root->data);
    for(int i=0;i<n&&root->children[i]!=NULL;i++)
    {
        serialize(root->children[i],fp);
    }

        fprintf(fp,"%c ",')');
}
int deserialize(struct node *&root,FILE *fp)
{
    char val;
    if(!fscanf(fp,"%c ",&val)||val==')')
        return 1;
    root=newNode(val);
    for(int i=0;i<n;i++)
    {
        if(deserialize(root->children[i],fp));
        break;
    }
    return 0;
}
void traverse(struct node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    for(int i=0;i<n;i++)
        traverse(root->children[i]);
}
int main()
{
    struct node *root = newNode('A');
    root->children[0] = newNode('B');
    root->children[1] = newNode('C');
    root->children[2] = newNode('D');
    root->children[0]->children[0] = newNode('E');
    root->children[0]->children[1] = newNode('F');
    root->
    children[2]->children[0] = newNode('G');
    root->children[2]->children[1] = newNode('H');
    root->children[2]->children[2] = newNode('I');
    root->children[2]->children[3] = newNode('J');
    root->children[0]->children[1]->children[0] = newNode('K');
    FILE *fp=fopen("fileforserialization.txt","w");
    if(fp==NULL)
        cout<<"couldnt find file!!"<<endl;
    else serialize(root,fp);
    fclose(fp);
    FILE *fd=fopen("fileforserialization.txt","r");
struct node *root1=NULL;
    deserialize(root1,fd);
    traverse(root1);
//    inorder(root1);
    return 0;

}


