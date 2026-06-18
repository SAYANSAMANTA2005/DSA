
#include<bits/stdc++.h>
#define  int double
using namespace std ;


double profit=0.00;
int weight ;
bool should_i_swap(pair<int,int>a, pair<int,int> b) {
    double v1= (double)a.first/a.second ;
    double v2= (double)b.first/b.second ;

    if(v1>v2)
        return true ;
//decreasing order accordingly to ratio




    else
        return false;

}



signed main() {

    vector<pair<int,int>>v= {{21,70},{24,40},{12,60},{40,50},{30,60}};



    sort(v.begin(),v.end(),should_i_swap);//
    //sorting of vector in cpp using stl

    //method for printing vector element method 1



    cout<<"method 3 for printing vector element "<<endl;
    for(int i=0; i<v.size(); i++) {

        cout << "value: " << v[i].first<<"; weight: "<<v[i].second<<"; value/weight:"<<v[i].first/v[i].second<< endl;
    }

    int maxweight=20.00;
    if(maxweight>=v[0].second) {
        profit=v[0].first;
        weight =v[0].second;
    }
    else {
        profit+=(v[0].first/v[0].second)*(maxweight);

        cout << "ratio1:" <<v[0].first/v[0].second << endl;
        cout << "profit1 "<<profit << endl;
        weight =maxweight;
    }

    cout << "profit11 :"<<profit<<" weight11: "<< weight<< " ratio:"<< v[0].first/v[0].second<< endl;

    for(int i=1; i<v.size(); i++) {

        if(weight<=maxweight&&weight+v[i].second<=maxweight) {

            profit+=v[i].first;
            weight +=v[i].second;
            cout << " profit3:"<<profit<<" weight:"<< weight<<" ratio: "<<v[i].first/v[i].second<< endl;
        }
        else if(weight+v[i].second>maxweight&& weight<maxweight) {
            cout << "profit4: "<<profit<<" weight:"<< weight<<" ratio:"<<v[i].first/v[i].second<< endl;

            profit+=(v[i].first/v[i].second)*(maxweight-weight);
            cout << " ratio"<< v[i].first/v[i].second<< endl;
            cout<< (v[i].first/v[i].second)*(maxweight-weight)<<endl;
            weight =maxweight;
            cout << "profit5: "<<profit<<" weight:"<< weight<< endl;
        }
        else break;
        //cout << "profit is:"<<profit << endl;

    }
    cout << "profit2 is:"<<profit << endl;


    return 0;
}