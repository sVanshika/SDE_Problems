/*
Ques: Find pair whose sum is equal to target
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    vector<int> nums = {2,6,5,8,11};
    int target=14;
    map<int, int> pair;
    for(int i=0; i<nums.size(); i++){
        if(pair.find(target - nums[i]) == pair.end()) //element does not exist
            pair.insert({nums[i], i});
        else{
            cout<<i<<" "<<pair.find(target - nums[i])->second<<endl;
            break;
        }
    }
    return 0;
}