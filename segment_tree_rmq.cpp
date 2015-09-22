#include<bits/stdc++.h>
using namespace std;

int constructutil(int arr[],int *st,int ss,int se,int index)
{
    if(ss==se)
    {
        st[index]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    st[index]=min(constructutil(arr,st,ss,mid,2*index+1),constructutil(arr,st,mid+1,se,2*index+2));
    return st[index];
}

int * construct(int arr[],int n)
{
    int h=ceil(log2(n));
    int max_size=2*(int)pow(2,h)-1;
    int *st=new int[max_size];
    constructutil(arr,st,0,n-1,0);
    return st;
}
int rmqutil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(ss>=qs && se<=qe)
        return st[index];
    if(ss>qe||se<qs)
        return INT_MAX;
    int mid=(ss+se)/2;
    return min(rmqutil(st,ss,mid,qs,qe,2*index+1),rmqutil(st,mid+1,se,qs,qe,2*index+2));
}
int rmq(int *st,int qs,int qe,int n)
{
    if(qs<0||qe>n-1||qs>qe)
        return -1;
    return rmqutil(st,0,n-1,qs,qe,0);
}
int main()
{
    int arr[10]={2,5,1,4,9,3};
    int *y=construct(arr,6);
    for(int i=0;i<13;i++)
        cout<<y[i]<<" ";
    cout<<endl;
    int u=rmq(y,3,5,6);
    cout<<u<<endl;
    return 0;
}
