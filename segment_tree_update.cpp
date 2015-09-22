#include<bits/stdc++.h>
using namespace std;

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
void update(int arr[],int *st,int n,int i,int new_val)
{
    if(i<0||i>n-1)
        return;
    int diff=new_val-arr[i];
    arr[i]=new_val;
    updateutil(st,0,n-1,i,diff,0);
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
    for(i=0;i<13;i++)
        cout<<y[i]<<" ";
    cout<<endl;
}

