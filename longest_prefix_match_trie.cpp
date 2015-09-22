#include<bits/stdc++.h>
using namespace std;
#define alpha 26
struct trie_node{
    int value;
    struct trie_node *children[alpha];
};

struct trie{
    int count;
    struct trie_node *root;
};

struct trie_node* getnode()
{
    struct trie_node *newnode=(trie_node*)malloc(sizeof(trie_node));
    newnode->value=0;
    int i;
    for(i=0;i<26;i++)
        newnode->children[i]=NULL;
        return newnode;
}

void initialize(struct trie **pp)
{
    (*pp)->root=getnode();
    (*pp)->count=0;
}
void insert(struct trie **ptrie,char key[])
{
    (*ptrie)->count++;
    int l=strlen(key);
    int i;
    struct trie_node *p=(*ptrie)->root;
    for(i=0;i<l;i++)
    {
        int index= (int)(key[i])-(int)'a';
        if(p->children[index]==NULL)
        {
            p->children[index]=getnode();
        }
        p=p->children[index];

    }
    p->value=(*ptrie)->count;
}
int search(struct trie *ptrie,char key[])
{
    int l=strlen(key);
    int i;
    struct trie_node *p=ptrie->root;
    for(i=0;i<l;i++)
    {
        int index= (int)(key[i])-(int)'a';
        if(p->children[index]==NULL)
        {
            return 0;;
        }
        p=p->children[index];

    }
    return p->value;
}

string searchpattern(struct trie *ptrie,char key[])
{
    int l=strlen(key);
    struct trie_node *p=ptrie->root;
    string result="";
    int i;
    for(i=0;i<l;i++)
    {
        int index=(int)(key[i])-(int)'a';
        if(p->children[index]!=NULL)
        {
            result+=key[i];
            p=p->children[index];
        }
        else return result;
    }
    return result;
}
int main()
{
    struct trie *ptrie;
    ptrie=(trie*)malloc(sizeof(trie));
    initialize(&ptrie);
    char key1[10]={'a','r','e','n','a'};
    char key4[10]={'a','r','e'};
  //  char key2[10]={'c','a','t','e','r'};
    char key3[10]={'b','a','s','e'};
    char key5[10]={'c','a','t','e','r','e','r'};

  //  insert(&ptrie,key1);
    insert(&ptrie,key3);
//    insert(&ptrie,key2);
    insert(&ptrie,key4);
//    string g=searchpattern(ptrie,caterer);
  //  cout<<g<<endl;
    string h=searchpattern(ptrie,key5);
    cout<<h<<endl;
    return 0;
}
