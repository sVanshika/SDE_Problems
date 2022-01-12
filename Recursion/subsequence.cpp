#include <iostream>
#include <vector>
using namespace std;

void create_sub(int i, int &n, vector<int> &arr, vector<int> &subArr){
    // cout << "i=" << i << endl;
    if(i == n){
        // print subArr
        for(int x=0; x<subArr.size(); x++) 
            cout << subArr[x] << " ";
        cout << endl;
        return; 
    }
    // picking arr[i]
    subArr.push_back(arr[i]);
    create_sub(i+1, n, arr, subArr);

    // not picking arr[i]
    subArr.pop_back();
    create_sub(i+1, n, arr, subArr);
}

int main(){
    vector<int> arr = {3,1,2};
    int n = arr.size();

    int i=0;
    vector<int> subArr;
    create_sub(i, n, arr, subArr);
    
    return 0;
}