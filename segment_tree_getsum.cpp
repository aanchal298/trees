#include<bits/stdc++.h>
using namespace std;
int getsumutil(int *st,int ss,int se,int qs,int qe,int index)
{
    if(ss>=qs&&se<=qe)
        return st[index];
    if(ss>qe || se<qs)
        return 0;
    int mid=(ss+se)/2;
    return (getsumutil(st,ss,mid,qs,qe,2*index+1)+getsumutil(st,mid+1,se,qs,qe,2*index+2));

}

int getsum(int *st,int n,int qs,int qe)
{
    if(qs<0 || qe>=n || qs>qe)
        return -1;
    return getsumutil(st,0,n-1,qs,qe,0);
}
int constructutil(int arr[],int ss,int se,int *st,int si)
{
    if(ss==se)
    {
        st[si]=arr[ss];
        return arr[ss];
    }
    int mid=(ss+se)/2;
    st[si]=constructutil(arr,ss,mid,st,2*si+1)+constructutil(arr,mid+1,se,st,2*si+2);
    return st[si];
}

int * construct(int arr[],int n)
{
    int x=(int)ceil(log2(n));
    int max_size=2*(int)pow(2,x) - 1;
    int *st=new int[max_size];
    constructutil(arr,0,n-1,st,0);
    return st;
}

int main()
{
    int arr[10]={1,3,5,7,9,11};
    int *y=construct(arr,6);
    int i;
    i=getsum(y,6,2,5);
    cout<<i<<endl;
}

