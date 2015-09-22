#include<bits/stdc++.h>
using namespace std;
#define n 8
struct node {
    int data;
    struct node *children[n];
};
struct node *newNode(int d)
{
    struct node *temp=(node*)malloc(sizeof(node));
    temp->data=d;
    int i;
    for(i=0;i<n;i++)
        temp->children[i]=NULL;
    return temp;
};
int countiter(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->children[0]==NULL)
    {
        return 0;
    }
    int cs=0;
    int i;
    for(i=0;i<n&&root->children[i];i++)
    {
        cs+=countiter(root->children[i]);
    }
    return max(cs,i);
}

int main()
{
    struct node *root=NULL;
    root=newNode(1);
    root->children[0]=newNode(2);
    root->children[1]=newNode(3);
    root->children[2]=newNode(4);
    root->children[3]=newNode(5);
    root->children[4]=newNode(6);
    root->children[5]=newNode(7);


    root->children[0]->children[0]=newNode(8);
    root->children[0]->children[1]=newNode(9);
    root->children[0]->children[2]=newNode(10);

    root->children[3]->children[0]=newNode(12);
    root->children[3]->children[0]=newNode(13);

    root->children[5]->children[0]=newNode(14);

    root->children[0]->children[1]->children[0]=newNode(15);
    root->children[0]->children[1]->children[1]=newNode(16);

    root->children[3]->children[0]->children[0]=newNode(17);
    root->children[3]->children[0]->children[0]=newNode(18);

    int i=countiter(root);
    cout<<i<<endl;

    return 0;
}
