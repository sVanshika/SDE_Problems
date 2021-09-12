/*
Ques: Given a mxn matrix, if an element is 0, set its entire row and column to zero

Time Complexity: O(n^2) + O(n x m)
Space Complexity: 
*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void convert(int a[3][3], int row, int col, int value);

int main(){
    int arr[3][3] = {{1,2,3},{4,0,5},{7,8,0}};
    int row=3, col=3;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 0)
                convert(arr, i, j, -1);
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }

    //output
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout << arr[i][j] << "\t";
        cout<<endl;
    }
    
    return 0;
}

void convert(int a[3][3], int row, int col, int value){
    for(int i=0; i<row; i++)
        if(a[i][col] != -1)
            a[i][col] = value;
    for(int i=0; i<col; i++)
        if(a[row][i] != -1)
            a[row][i] = value;
}