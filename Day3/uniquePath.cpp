/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

int path(int i, int j, int row, int col);
int pathDP(int i, int j, int row, int col, vector<vector<int>> &mat);

int main(){
    int row=23, col=12;
    
    //Simple recursion
    //int totalPaths = path(0,0,row,col);

    //Dynamic Programming
    //vector<vector<int>> mat(row, vector<int>(col, -1));
    //int totalPaths = pathDP(0,0,row,col,mat);
    
    //Combinatorics
    long num=(row+col-2), deno=1;

    int limit = min(row, col);
    for(int i=2; i<=(limit-1); i++){
        deno = deno*i;
        num = num * (row+col-i);
    }
    cout<<num<<" "<<deno<<endl;
    long totalPaths = num/deno;

    cout << totalPaths << endl;
    return 0;
}

//Dynamic Programming approach
int pathDP(int i, int j, int row, int col, vector<vector<int>> &mat){
    //cout<<i<<" "<<j<<endl;
    if(i >= row || j >= col)
        return 0;
    else if(i == (row-1) && j == (col-1))
        return 1;
    else if(mat[i][j] != -1)
        return mat[i][j];
    else 
        return mat[i][j] = pathDP(i+1, j, row, col, mat) + pathDP(i, j+1, row, col, mat);
}

//Simple recursive approach
int path(int i, int j, int row, int col){
    if(i >= row || j >= col)
        return 0;
    else if(i == (row-1) && j == (col-1))
        return 1;
    else
        return path(i+1, j, row, col) + path(i, j+1, row, col);
}