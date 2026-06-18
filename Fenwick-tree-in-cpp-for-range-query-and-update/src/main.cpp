#include <iostream>
#include <vector>

using namespace std;

#define n 10


vector <int>arr={1,2,3,4,5,6,7,8,9,10};

vector <int>bit(n+1,0);


void update(int idx,int add_val){

for(int i=idx;i<=n;i=i+(i&(-i))){

bit[i]=bit[i]+add_val;

}

return ;

}

void build_bit() {
    for (int j = 1; j <= n; ++j) {
        
        for(int i=j;i<=n;i=i+(i&(-i))){

        bit[i]=bit[i]+arr[j-1];

          }
    }
}

int sum(int idx) {
    //int a = i;
    int ans = 0;
    for (int i = idx; i > 0; i = i - (i & (-i))) {
    
        ans = ans + bit[i];
    }
    return ans;
}





int main (){


build_bit();


cout << "array:" << endl;
for(int i=0;i<n;i++){
cout<<" arr["<<i<<"] ->"<<arr[i]<<endl;}

cout << "array end :\n" << endl;


cout << "bit:" << endl;
for(int i=1;i<=n;i++){
cout<<" bit["<<i<<"] ->"<<bit[i]<<endl;}

cout << "bit end :\n" << endl;

cout << "sum:" << endl;

for(int j=1;j<=n;j++){
cout<<"sum"<<"["<<j<<"] ->"<<sum(j)<<endl;

}

cout << "sum end \n" << endl;


update(3, 20);


cout << "sum after update(idx=3,add_val=20):" << endl;

for(int j=1;j<=n;j++){
cout<<"sum"<<"["<<j<<"] ->"<<sum(j)<<endl;

}

cout << "sum end \n" << endl;




return 0;



}