#include <iostream>
using namespace std;

bool search(int arr[], int low, int high, int value){
    if(low > high)
        return false;
    int mid = (low + high)/2;
    if(arr[mid] == value)
        return true;
    else if(arr[mid] < value)
        return search(arr, mid+1, high, value);
    else    
        return search(arr, low, mid-1, value);
}

int main(){
    int arr[5] = {10, 20, 30, 50, 79};
    int value;
    cin >> value;
    cout << search(arr, 0, 4, value) << endl;
    return 0;
}