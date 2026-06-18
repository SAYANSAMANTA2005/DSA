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

tree[node]=max(tree[2*node],tree[2*node+1]);


}



int query(int node,int st,int en,int l,int r){

int mid=(st+en)/2;
//partial overlaping
//return tree[node];


if(st>r || en<l){ return INT_MIN;}


if(st>=l&&en<=r){//complete overlaping
return tree[node];



}


int q1=query(2*node, st,mid, l, r);

int q2=query(2*node+1,mid+1,en, l, r);
 return max(q1,q2);
 }

int main() 
{
    
    int n;
    
    //cin>>n;
    cout << "enter the size of array: " << endl;
    cin>>n;
    cout << "enter the elements of array: " << endl;
    for(int i=0;i<n;i++){
    cin>>a[i];
    
    }
    
    build(1,0,n-1);
    
    
    while(1){
    cout << "if u want to break the loop press -1" << endl;
    int x;
    cin>>x;
    if(x==-1){break;}
    else{
    int l,r;
    
    cout << "enter the range of query l and r: " << endl;
    
    
    cin>>l>>r;
    
    
    cout<< query(1,0,n-1,l,r)<<endl;
    
    }}
    //cout << " "<<tree[n/2] << endl;
    cout << "tree is " << endl;
    //for(int i=0;i<=n;i++){
    
    //cout << i<<"->"<<tree[i] << endl;
    //}
    
    
    
    
    return 0;
}