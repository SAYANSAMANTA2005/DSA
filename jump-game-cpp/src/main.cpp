#include <iostream>
#include <vector>

using namespace std;



vector <int>arr= {3,0,0,1};

int n=arr.size();

vector <int>possible_sol_arr(n,INT_MAX);

void jumpgamesolve() {

    int k=0;
    possible_sol_arr[0]=INT_MAX;

    int count=0;
    while(k<=n&& count<=1) {
//cout << "k ->"<<k << endl;
        int i=n-1;
        while(i>=0&k<=n) {

            cout << "count of total steps ->"<<i << endl;

            if(arr[i]==0) {
                i=i-1;

            }
            else {
                if(i+arr[i]>=n-1) {
                    possible_sol_arr[k+1]=i;

                    cout << "i is "<<i <<" arr["<<i<<"]->"<<arr[i]<< endl;
                }

                else if(i+arr[i]>=possible_sol_arr[k]) {
                    possible_sol_arr[k+1]=i;
                    cout << "i  is "<<i<<" arr["<<i<<"]->"<<arr[i] << endl;

                }
                else {
                    possible_sol_arr[k+1]=INT_MAX;


                }

                k++;
                i--;
                cout << "k inside->"<<k << endl;
                cout << "i inside->"<<i << endl;
            }
        }
        count=1;
        cout << "count of total steps out ->"<<k << endl;

    }


    int ans=1;
    for(int i=1; i<n; i++) {
        if(possible_sol_arr[i]==INT_MAX) {
            ans=0;
        }
//cout <<i<<"->"<<"arr["<<i<<"]->idx of possisolu of arr :" << possible_sol_arr[i]<< endl;

    }
    if(ans==1) {

        cout << "solution exist" << endl;
    }
    else {
        cout << "no solution" << endl;
    }
}



int main () {

    jumpgamesolve();

    return 0;

}