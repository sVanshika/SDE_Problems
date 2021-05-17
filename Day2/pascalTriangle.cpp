/*
Ques: Pascal Triangle
Time Complexity: O(n^2)
Space Complexity: O(nxm)
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numRows = 5;
    vector<vector<int>> p;

    for(int i=0; i<numRows; i++)
    {
        vector<int> temp;
        for(int j=0; j<=i; j++)
        {
            if(j==0 || j==i) 
                temp.push_back(1);
            else
                temp.push_back(p[i-1][j-1] + p[i-1][j]);
            
        }
        p.push_back(temp);
    }

    for(auto i: p){
        for(int j: i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
