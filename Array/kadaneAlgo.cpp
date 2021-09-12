/*
Time Complexity: Brute: O(n^2) Optimal:O(n)
Space Complexity: 
*/
#include <iostream>
#include <climits>
using namespace std;

//O(n^2)
long long maxSubarraySum_Brute(int a[], int n){
    int max = INT_MIN, sum=0, start, end, i, j;
    for(i=0; i<n; i++){
        sum = a[i];
        for(j=i+1; j<n; j++){
            sum += a[j];
            max = (sum>max) ? sum : max;
        }
    }
    return max;
}

//O(n)
long long maxSubarraySum_Optimal(int a[], int n){
    int maxCurrent, maxGlobal;
    maxCurrent = maxGlobal = a[0];

    for(int i=1; i<n; i++){
        maxCurrent = (a[i] > maxCurrent+a[i]) ? a[i] : maxCurrent+a[i];
        maxGlobal = (maxCurrent > maxGlobal) ? maxCurrent : maxGlobal; 
    }

    return maxGlobal;
}

int main(){
    int arr[] = {1, -3, 2, 1, -1};
    int n=sizeof(arr)/sizeof(int);
    cout << "Brute: " << maxSubarraySum_Brute(arr, n) << endl;
    cout << "Optimal: " << maxSubarraySum_Optimal(arr, n) << endl;
    return 0;
}    
 