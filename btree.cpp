#include<bits/stdc++.h>
using namespace std;



int main()
{
    string A;
    cin>>A;
    int i,j;
    int l=A.length();
    for(i=0;i<l;)
    {
        if(A[i]==32)
            i++;
        if(A[i]=='{' || A[i]=='(' || A[i]== '[')
        {
            cout<<A[i]<<"\n"<<"\t";
            i++;
        }
        else if(A[i]=='}' || A[i]==')' || A[i]==']')
        {
            cout<<A[i]<<"\n"<<"\b";
            i++;
        }
        else if(A[i]==',')
        {
            cout<<A[i]<<"\n";
            i++;
        }
        else
        {
            cout<<A[i];
            i++;
        }
    }
    return 0;
}
