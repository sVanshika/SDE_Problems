/*
Ques: 
Time Complexity: O(n^2)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {3,1,2};
    int count=0;

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(i<j && arr[i]>arr[j]){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
                count++;
            }
        }
    }
    cout<<"Inversions:"<<count<<endl;
    
    return 0;
}