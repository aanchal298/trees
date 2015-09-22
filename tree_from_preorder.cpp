#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *newNode(int num)
{
    struct node *p=(node*)malloc(sizeof(node));
    p->data=num;
    p->left=NULL;
    p->right=NULL;
    return p;
};
int nextgreater(int arr[],int s,int e,int x)
{
    int i;
    for(i=s;i<e;i++)
    {
        if(arr[i]>x)
            return i;
    }
    return -1;
}
int pi=0;
struct node * construct (int pre[],int s,int e,int n)
{
    if(pi>n || s>e)
        return NULL;
    struct node *root=newNode(pre[pi]);
    if(s==e)
        return root;
    int i=nextgreater(pre,pi+1,e,pre[pi]);
    pi++;
    root->left=construct(pre,pi,i-1,n);
    root->right=construct(pre,i,e,n);
    return root;
};
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = construct(pre,0,size-1, size);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}
