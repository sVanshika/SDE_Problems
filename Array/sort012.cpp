/*
Ques: Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
using namespace std;

// Brute Force - O(n+n)
void sortColors(vector<int>& nums){
    int len = nums.size();       
    int zero=0, one=0, two=0;
        
    for(int i=0; i<len; i++){
        if(nums[i] == 0) zero++;
        else if (nums[i] == 1) one++;
        else two++;
    }
        
    printf("zero=%d , one=%d , two=%d\n", zero, one, two);
        
    int i,j;
    for(i=0; i<zero; i++)
        nums[i]=0;
    for(j=i; j<i+one; j++)
        nums[j]=1;
    for(i=j; i<j+two; i++)
        nums[i]=2;
}

// OPTIMAL - 3 pointer technique - O(n)
/*
elements before low = 0
low to high = 1
after high = 2
*/
void sortColorsOptimal(vector<int> &nums){
    int low=0, mid=0, high=nums.size()-1;
    for(int i=0; i<nums.size(); i++){

    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);

    for(int i:nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}