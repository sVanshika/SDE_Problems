/*
Ques: 
Time Complexity: Optimal=O(n); Brute=O(n^2)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    vector<int> prices = {6,5,4,3,1,2};
    int minValue=INT_MAX, profit=0;

    auto start = high_resolution_clock::now();
    min(3,6);
    auto stop = high_resolution_clock::now();
    cout << duration_cast<microseconds>(stop - start).count() << endl;

    for(int i=0; i<prices.size(); i++){
        /*
        if(prices[i]<minValue)
            minValue = prices[i];
        else if(prices[i]-minValue > profit) 
            profit = prices[i]-minValue;
        */

        minValue = min(minValue, prices[i]);
        profit = max(prices[i]-minValue, profit);

    }
    cout<<profit;
    /* 
    ==== O(n^2) ===== 
    int max=0;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j] > prices[i] && prices[j]-prices[i]>max){
                max = prices[j]-prices[i];
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<max<<endl;
    */

    return 0;
}