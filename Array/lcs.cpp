/*
Ques: longest consecutive sequence 
Time Complexity: O(n) + O(n) + O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> nums = {5, 4, 3, 2, 1};
    
    //Brute -> sort the array, then find the longest sequence
    //Time: O(nlogn)+O(n) Space:O(1)

    //Optimal -> Using map
    set<int> s;
    int value, count=0, max=0;

    for(int i: nums)
        s.insert(i);
    
    for(int i=0; i<nums.size(); i++){
        if(s.find(nums[i]-1) == s.end()){ //check for next values
            value = nums[i];
            while(true){
                if(s.find(value) != s.end()){
                    value++;
                    count++;
                }
                else
                    break;
            }
            if(count > max){
                max = count;
                count = 0;
            }
        }
    }

    cout << max << endl;

    return 0;
}