/*
Ques: Find a subarray having xor equals to given value
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {4,2,2,6,4};
    int k = 6;
    int x = 0;

    for(int i=0; i<nums.size(); i++){
        x=0;
        for(int j=i; j<nums.size(); j++){
            x = x ^ nums[j];
            if(x == k){
                cout<<i<<","<<j<<endl;
            }
        }
    }    
    return 0;
}