#include<bits/stdc++.h>

using namespace std ;

bool is_positive(int x) {
    return x>0;
}



int main() {

    vector<int>v= {1,3,5,8,9};
    int x=-10;
    int y=x>0;
    cout << ""<<y << endl;
    cout << ""<<boolalpha<<(x>0 )<< endl;
    cout << boolalpha<<all_of(v.begin(),v.end(),[](int x) {
        return x>0;
    }) << endl;
    cout << boolalpha<<all_of(v.begin(),v.end(),is_positive) << endl;
    cout <<[](int x) {
        return x+2;
    }
    (2)<<endl;
    auto sum= [](int x) {
        return x+2;
    };
    cout << " "<<sum(4) << endl;
    cout <<[](int x,int y) {
        return x+y;
    }
    (7,6)<<endl;


    return 0;
}