#include<bits/stdc++.h>
using namespace std;


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
