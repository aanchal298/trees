#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
struct node *left,*right,*nright;
};
struct node *getright(struct node *temp)
{
    struct node *p=temp->nright;
    while(p)
    {
        if(p->left)
            return p->left;
        if(p->right)
            return p->right;
        p=p->nright;
    }
    return NULL;
};
void connectrecur(struct node *root)
{
    if(root==NULL)
        return;
    if(root->nright!=NULL)
        connectrecur(root->nright);
    if(root->left)
    {
        if(root->right)
        {
            root->left->nright=root->right;
            root->right->nright=getright(root);
        }
        else
            root->left->nright=getright(root);
        connectrecur(root->left);
    }
    else if(root->right)
    {
        root->right->nright=getright(root);
        connectrecur(root->right);
    }
    else connectrecur(getright(root));

}

void connect(struct node *root)
{
    if(root==NULL)
        return;
    root->nright=NULL;
    connectrecur(root);
}
struct node* newnode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->nright = NULL;

    return(node);
}

int main()
{
   struct node *root = newnode(10);
    root->left        = newnode(8);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->right->right       = newnode(90);

    // Populates nright pointer in all nodes
    connect(root);

    // Let us check the values of nright pointers
    printf("Following are populated nright pointers in the tree "
           "(-1 is printed if there is no nright) \n");
    printf("nright of %d is %d \n", root->data,
           root->nright? root->nright->data: -1);
    printf("nright of %d is %d \n", root->left->data,
           root->left->nright? root->left->nright->data: -1);
    printf("nright of %d is %d \n", root->right->data,
           root->right->nright? root->right->nright->data: -1);
    printf("nright of %d is %d \n", root->left->left->data,
           root->left->left->nright? root->left->left->nright->data: -1);
    printf("nright of %d is %d \n", root->right->right->data,
           root->right->right->nright? root->right->right->nright->data: -1);

    getchar();
    return 0;
}
