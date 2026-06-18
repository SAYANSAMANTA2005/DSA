#include<bits/stdc++.h>

using namespace std ;

bool is_positive(int x) {
    return x>0;
}



int main() {

    vector<int>v= {10,30,-4,8,90};
    int x=-10;
    int y=x>0;
    printf("sayan");
    cout << ""<<y << endl;
    cout << ""<<boolalpha<<(x>0 )<< endl;
    cout << boolalpha<<all_of(v.begin(),v.end(),[](int x) {
        return x%2==0;
    }) << endl;
    cout << boolalpha<<all_of(v.begin(),v.end(),is_positive) << endl;
    cout << boolalpha<<any_of(v.begin(),v.end(),is_positive) << endl;
        cout << boolalpha<<none_of(v.begin(),v.end(),is_positive) << endl;
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