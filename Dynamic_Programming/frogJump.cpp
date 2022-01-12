#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int count(int i, vector<int> &heights, vector<int> &dp){
    if(i == 0)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];

    int left = count(i-1, heights, dp) + abs(heights[i] - heights[i-1]);
    int right = INT_MAX;
    if(i > 1)
        right = count(i-2, heights, dp) + abs(heights[i] - heights[i-2]);
    
    return dp[i] = min(left, right);
}

int count_k(int index, int k, vector<int> &heights, vector<int> &dp){
    if(index == 0)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];

    int step, min_energy = INT_MAX;
    for(int x=1; x<=k; x++){
        if(index-x >= 0){
            step = count(index-x, heights, dp) + abs(heights[index]- heights[index-x]);
            min_energy = min(min_energy, step);
        }
    }

    return dp[index] = min_energy;
}

int main(){
    int n;
    cout << "n=";
    cin >> n;
    
    vector<int> heights;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        heights.push_back(a);
    }
    
    vector<int> dp(n+1, -1);
    cout << "allowed 2 steps:" << endl << count(n-1, heights, dp) << endl;
    
    int k;
    cout << "allowed k steps:" << endl;
    cout << "k=";
    cin >> k;
    cout << count_k(n-1, k, heights, dp) << endl;
    return 0;
}