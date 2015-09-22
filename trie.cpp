#include<bits/stdc++.h>
using namespace std;

#define alphabets 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct trie_node{
    int value;
    struct trie_node *children[alphabets];
};

struct trie{
    int count;
    struct trie_node *root;
};

struct trie_node * getnode()
{
    //cout<<"bitch"<<endl;
    struct trie_node *newnode=NULL;
    newnode=(trie_node*)malloc(sizeof(trie_node));
    newnode->value=0;
    for(int i=0;i<alphabets;i++)
    {
        newnode->children[i]=NULL;
    }
    return newnode;
}
void initialize(struct trie **ptrie)
{
    (*ptrie)->root=getnode();
    (*ptrie)->count=0;
    //cout<<"kqgd"<<endl;
}



void insertnode(struct trie **ptrie,char key[])
{
    (*ptrie)->count=(*ptrie)->count + 1;
    int i;
    int length=strlen(key);
   //cout<<"Length="<<length<<endl;
    struct trie_node *p=(*ptrie)->root;
    for(i=0;i<length;i++)
    {
        int index=CHAR_TO_INDEX(key[i]);

        if(!p->children[index])
        {
            p->children[index]=getnode();
        }
        p=p->children[index];
    }
    p->value=(*ptrie)->count;

}

int searchnode(struct trie *ptrie,char key[])
{
    int i;
    int length=strlen(key);
    struct trie_node *p=ptrie->root;
    for(i=0;i<length;i++)
    {
        int index=CHAR_TO_INDEX(key[i]);
        if(p->children[index]==NULL)
        {
            return 0;
        }
        p=p->children[index];
    }
    return p->value;
}


int main()
{
    struct trie *ptrie;
    ptrie=(trie*)malloc(sizeof(trie));
    initialize(&ptrie);
    char key1[10]={'b','l','u','e'};
    char key2[10]={'b','l','a','c','k'};
    char key3[10]={'b','l','u','n','d'};

    insertnode(&ptrie,key1);
    insertnode(&ptrie,key3);
    int yy=searchnode(ptrie,key2);
    cout<<yy<<endl;
    int zz=searchnode(ptrie,key1);
    cout<<zz<<endl;
    return 0;
}
