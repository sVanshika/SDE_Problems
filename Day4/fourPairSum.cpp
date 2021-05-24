/*
Ques: Extract pair of 4 from array whose sum is equal to target
Time Complexity: O(n^3 x logn)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> nums, int low, int high, int value);

int main(){
    vector<int> nums = {1,0,-1,0,-2,2};
    int target=0;
    
    sort(nums.begin(), nums.end());
    int value=0;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                value = target - (nums[i] + nums[j] + nums[k]);
                //cout<<nums[i]<<","<<nums[j]<<","<<nums[k]<<","<<value<<endl;
                if(binarySearch(nums, k+1, nums.size()-1, value))
                    cout<<nums[i]<<","<<nums[j]<<","<<nums[k]<<","<<value<<endl;
            }
        }
    }
    

    return 0;
}

bool binarySearch(vector<int> nums, int low, int high, int value){
    if(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == value)
            return true;
        else if(nums[mid] > value)
            return binarySearch(nums, low, mid-1, value);
        else
            return binarySearch(nums, mid+1, high, value);
    }
    return false;

}