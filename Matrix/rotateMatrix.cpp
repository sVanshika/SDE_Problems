/*
Ques: Rotate matrix by 90 degree
Time Complexity: O(n^2)
Space Complexity: O(nm)+ O(n) -> O(nm)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    int rows=matrix.size(), cols=matrix[0].size();

    vector<vector<int>> ans;

    for(int i=0; i<cols; i++){
        vector<int> temp;
        for(int j=0; j<rows; j++)
            temp.insert(temp.begin(), matrix[j][i]);
        ans.push_back(temp);
    }

    for(auto i: ans){
        for(int j: i)
            cout<<j<<"\t";
        cout<<endl;
    }    

    return 0;
}