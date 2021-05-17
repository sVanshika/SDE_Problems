/*
Ques: Write an efficient algorithm that searches for a value in an m x n matrix. Matrix is sorted.
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=7, i=0;

    for(i=0; i<matrix.size()-1; i++){
        if(matrix[i+1][0] > target) //search in i-1th row
            break;
    }

    int low=0, mid, high=matrix[0].size()-1;
    for(int j=0; j<(matrix[0].size()); j++){
        mid = (low + high)/2;
        cout<<"low: "<<low<<" mid: "<<mid<<" high: "<<high<<endl;
        if(matrix[i][mid] == target){
            cout<<"True"<<endl;
            break;
        }
        else if(matrix[i][mid] > target)
            high=mid-1;
        else
            low=mid+1;

    }
    return 0;
}

