/*
Ques: Largest subarray with sum 0
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int subarray(vector<int> nums);
int subarrayOptimal(vector<int> nums);

int main(){
    vector<int> nums = {-1,1,-1,1};
    int maxLength=0, sum=0;

    // BRUTE -> Time: O(n^2) Space: O(1)
    //maxLength = subarray(nums);

    //Optimal -> Time: O(n) Space: O(n)
    maxLength = subarrayOptimal(nums);

    cout<<maxLength<<endl;

    return 0;
}

//Brute
int subarray(vector<int> nums){
    int maxLength=0, sum=0;
    for(int i=0; i<nums.size(); i++)
    {
        sum = nums[i];
        for(int j=i+1; j<nums.size(); j++)
        {
            sum += nums[j];
            if(sum == 0 && (j-i+1) > maxLength) 
                maxLength = j-i+1;
        }
    }

    return maxLength;
}

//Optimal
int subarrayOptimal(vector<int> nums){
    int sum=0, maxLength=0;
    map<int, int> s; 
    map<int, int>::iterator itr;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        itr = s.find(sum);
        //cout<<"sum:"<<sum<<endl;
        //cout << "found in map: " << (itr->first) << "," << (itr->second) << " i: " << i << endl;      
        if(sum == 0)
            maxLength = i+1; 
        else if(itr != s.end())
            maxLength = max(maxLength, i-(itr->second));
        else   
            s.insert({sum, i});
        
        //cout << "** max: " << maxLength << endl;
    }
    return maxLength;

}