/*
Ques: Write an efficient algorithm that searches for a value in an m x n matrix. Matrix is sorted.
Time Complexity: O(logn)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=30, i=0, j=matrix[0].size()-1;

    //O(logn)
    while(0<=i<matrix.size() && 0<=j<matrix[0].size()){
        if(matrix[i][j] == target){
            cout<<"True "<<i<<" "<<j<<endl;
            break;
        }
        else if(matrix[i][j] > target)
            j--;
        else
            i++;
    }


    // ** BINARY SEARCH ** -> O(n) + O(log n)
    // for(i=0; i<matrix.size()-1; i++){
    //     if(matrix[i+1][0] > target) //search in i-1th row
    //         break;
    // }
    // int low=0, high=matrix[i].size(), mid=0;
    
    // while(low<=high){
    //     mid=(low+high)/2;
    //     if(matrix[i][mid] == target){
    //         cout<<"True";
    //         break;
    //     }
    //     else if(matrix[i][mid] > target)
    //         high = mid-1;
    //     else    
    //         low = mid+1;
    // }

    return 0;
    
}

