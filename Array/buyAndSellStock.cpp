/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
int maxProfit(vector<int> &prices){
    int profit=0, buy;

    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            if(prices[j] > prices[i])
                profit = max(profit, prices[j]-prices[i]);
        }
    }
    return profit;
}

// O(n)
int maxProfitOptimal(vector<int> &prices){
    int profit=0, minPrice=prices[0];

    for(int i=0; i<prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i] - minPrice);
    }
    
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
    cout << maxProfitOptimal(prices) << endl;
    return 0;
}