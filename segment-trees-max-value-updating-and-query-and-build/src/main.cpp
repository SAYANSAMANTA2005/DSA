#include<bits/stdc++.h>


#define int long long


using namespace std ;

const int N=1e5+2;

int a[N],tree[N];


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
 
 
 
 
 
void update(int node,int st,int en,int idx,int val){


 //return ;
if(st==en){

a[st]=val;
tree[node]=a[st];

return ;
}//base case

int mid=(st+en)/2;

if(idx<=mid){

update(2*node,st,mid,idx,val);//left child
}

else{
update(2*node+1,mid+1,en,idx,val);//right child 
}

tree[node]=max(tree[2*node],tree[2*node+1]);

 }
 
 
signed main() 
{
    
    int n;
    
    //cin>>n;
    cout << "enter the size of array: " << endl;
    cin>>n;
    cout << "enter the elements of array: " << endl;
    for(int i=0;i<n;i++){
    cin>>a[i];
    
    }
    
   
    cout << "enter the idx and val of updating index" << endl;
    int idx,val;
    cin>>idx>>val;
   // update(idx, val);
   update(1,0,n-1, idx, val);
    
    build(1,0,n-1);
    
    
    while(1){
    cout << "if u want to break the loop press -1" << endl;
    int x;
    cin>>x;
    if(x==-1){break;}
   cout << "your tree value are" << endl;
   for(int i=0;i<7;i++){
    cout << tree[i+1] << endl;}
    cout << "your tree value end here" << endl;
    
   cout<< query(1,0,n-1,1,n-1)<<endl;
    
    }
    
    return 0;
}