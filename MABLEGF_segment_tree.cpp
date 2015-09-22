#include<bits/stdc++.h>
using namespace std;
int arr[1000005];

int getsumutil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(ss>=qs&&se<=qe)
        return st[index];
    if(se<qs||ss>qe)
        return 0;
    int mid=(ss+se)/2;
    return(getsumutil(st,ss,mid,qs,qe,2*index+1)+getsumutil(st,mid+1,se,qs,qe,2*index+2));
}

int getsum(int *st,int qs,int qe,int n)
{
    if(qs<0||qe>n-1||qs>qe)
        return -1;
    return getsumutil(st,0,n-1,qs,qe,0);
}
void updateutil(int *st,int ss,int se,int i,int diff,int index)
{
    if(i<ss||i>se)
        return;
    st[index]+=diff;
    if(ss!=se)
    {
        int mid=(ss+se)/2;
        updateutil(st,ss,mid,i,diff,2*index+1);
        updateutil(st,mid+1,se,i,diff,2*index+2);
    }
}
void update(int arr[],int *st,int n,int i,int diff)
{
    if(i<0||i>=n)
        return;
    arr[i]+=diff;
    updateutil(st,0,n-1,i,diff,0);
}
int constructutil(int arr[],int *st,int ss,int se,int index)
{
    if(ss==se)
    {
        st[index]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    st[index]=constructutil(arr,st,ss,mid,2*index+1)+constructutil(arr,st,mid+1,se,2*index+2);
    return st[index];
}

int * construct(int arr[],int n)
{
    int x=(int)ceil(log2(n));
    int max_size=2*(int)pow(2,x) - 1;
    int *st=new int[max_size];
    constructutil(arr,st,0,n-1,0);
    return st;
}

int main()
{
    char task;
    int num1,num2;
    int n,q;
    cin>>n>>q;
    int i,j;
    int *y;
    for(i=0;i<n;i++)
        cin>>arr[i];
    y=construct(arr,n);
    for(i=0;i<q;i++)
    {
        cin>>task>>num1>>num2;
        if(task=='S')
        {
            cout<<getsum(y,num1,num2,n)<<endl;
        }
        if(task=='G')
        {
            update(arr,y,n,num1,num2);
        }
        if(task=='T')
        {
            num2=0-num2;
            update(arr,y,n,num1,num2);
        }
    }
    return 0;
}
