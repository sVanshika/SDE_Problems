#include <iostream>
#include <vector>
using namespace std;

// memoization: time = O(2^n) space = O(n+n)
int maxSum(int index, vector<int> &nums, vector<int> &dp){
    if(index == 0)
        return nums[0];
    if(index < 0)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    int picked = nums[index] + maxSum(index-2, nums, dp);
    int notPicked = 0 + maxSum(index-1, nums, dp);
    return dp[index] = max(picked, notPicked);
}

// tabulation: time = O(n) space = O(n)
int maxSumTabulation(int n, vector<int> &nums){
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for(int i=0; i<n; i++){
        int picked = nums[i];
        if(i > 1)
            picked += dp[i-2];
        int notPicked = 0 + dp[i-1];
        dp[i] = max(picked, notPicked);
    }
    return dp[n-1];
}

// space optimsation: time = O(n) space = O(1)
int maxSumSpaceOptimised(int n, vector<int> &nums){
    int prev = nums[0];
    int prev2 = 0;
    int curr = 0;

    for(int i=1; i<n; i++){
        int picked = nums[i];
        if(i > 1)
            picked += prev2;
        int notPicked = 0 + prev;
        curr = max(picked, notPicked);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main(){
    vector<int> nums = {1,2,3,5,4};
    int n = nums.size();
    vector<int> dp(n, -1);

    cout << maxSum(n-1, nums, dp) << endl;
    cout << maxSumTabulation(n, nums) << endl;    
    cout << maxSumSpaceOptimised(n, nums) << endl;    
    
    return 0;
}