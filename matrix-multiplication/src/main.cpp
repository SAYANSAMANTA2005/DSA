#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the first matrix
    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> r1 >> c1;

    // Input dimensions of the second matrix
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> r2 >> c2;

    // Check if the matrices can be multiplied
    if (c1 != r2) {
        cout << "Error: Matrices cannot be multiplied. Number of columns in the first matrix must equal the number of rows in the second matrix." << endl;
        return 1;
    }

    // Declare the matrices
    int matrix1[r1][c1], matrix2[r2][c2];
    //vector<vector <int>mult(r1,(vector<int>c2,0));

    // Input elements of the first matrix
    cout << "Enter elements of the first matrix:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Input elements of the second matrix
    cout << "Enter elements of the second matrix:" << endl;
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> matrix2[i][j];
        }
    }
    
for(int i=0;i<r1;i++){
for(int j=0;j<c2;j++){
for(int k=0;k<r2;k++){
mult[i][j] += matrix1[i][k]*matrix[k][j];
}
}
}

    cout << "Matrices can be multiplied." << endl;

    return 0;
}