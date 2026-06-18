#include<bits/stdc++.h>

using namespace std ;

const int N=1e5+2;

int a[N],tree[4*N];


void build(int node,int st,int en){//node==index of node

if(st==en){
tree[node]=a[st];

return ;
}//base case

int mid=(st+en)/2;

build(2*node,st,mid);//left child
build(2*node+1,mid+1,en);//right child 

tree[node]=tree[2*node]+tree[2*node+1];


}

int main() 
{
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
    cin>>a[i];
    
    }
    
    build(1,0,n-1);
    
    //cout << " "<<tree[n/2] << endl;
    cout << "tree is " << endl;
    for(int i=0;i<=n;i++){
    
    cout << i<<"->"<<tree[i] << endl;
    }
    
    return 0;
}