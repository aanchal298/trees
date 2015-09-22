#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    //cout<<&a;
    int temp;
    temp=a;
    a=b;
    b=temp;
    //cout<<a;
}



int main()
{
    int x=5;
    int y=6;
    //cout<<x<<endl;
    //cout<<&x;
    swap(x,y);
    cout<<(int)'t'-(int)'a';
    return 0;
}
