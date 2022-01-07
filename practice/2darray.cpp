#include <iostream>
using namespace std;



int main(){
    int row, col;
    cin >> row >> col;

    // declaring an array of pointers in heap memory
    int** arr = new int*[row];
    // assigning pointer to array
    for(int i=0; i<row; i++){
        arr[i] = new int[col];
    }

    // taking input
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }

    // printing
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // free memory
    for(int i=0; i<row; i++)
        delete [] arr[i];
    delete [] arr;

    return 0;
}