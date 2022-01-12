#include <iostream>
using namespace std;

int fibo(int n, int* dp){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    else{
        dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
        return dp[n];
    }
}


int main(){
    int n;
    cin >> n;

    // declaring dp array for memoization
    int* dp = new int[n+1];
    for(int i=0; i<(n+1); i++){
        dp[i] = -1;
    }

    cout << "fibonacci nth term = " << fibo(n, dp) << endl;
    return 0;
}