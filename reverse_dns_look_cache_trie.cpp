#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    char *url;
    struct node *children[11];
};
struct  trie
{
    int count;
    struct node *root;
};
struct node *getnode()
{
    struct node *temp=NULL;
    temp=(node*)malloc(sizeof(node));
    int i;
    for(i=0;i<11;i++)
        temp->children[i]=NULL;
    return temp;
};
void initialize(struct trie **ptrie)
{
    (*ptrie)->count=0;
    (*ptrie)->root=getnode();
}

void insert(struct trie *ptrie,char key[],char url[])
{
    int len=strlen(key);
    struct node *p=ptrie->root;
    int i,index;
    for(i=0;i<len;i++)
    {
        char q=key[i];
        if(q=='.')
            index=10;
        else index=(int)q-48;
        if(p->children[index]==NULL)
        {
            p->children[index]=getnode();
        }
        p=p->children[index];
    }
    p->url=url;
    ptrie->count++;
}
int search(struct trie *ptrie,char key[])
{
    int len=strlen(key);
    struct node *p=ptrie->root;
    int i,index;
    for(i=0;i<len;i++)
    {
        char q=key[i];
        if(q=='.')
            index=10;
        else index=(int)q-48;
        if(p->children[index]==NULL)
            return 0;
        p=p->children[index];
    }
    cout<<p->url<<endl;
    return 1;
}
int main()
{
   struct trie *ptrie=(trie*)malloc(sizeof(trie));
   initialize(&ptrie);
   insert(ptrie,"172.16.0.1","captive portal");
   insert(ptrie,"172.16.0.2","www.samsung.com");
    insert(ptrie,"198.16.0.1","facebook.com");

   search(ptrie,"198.16.0.1");
    return 0;
}
