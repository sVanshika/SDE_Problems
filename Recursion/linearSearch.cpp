#include <iostream>
using namespace std;

bool isPresent(int* arr, int size, int value){
    if(size == 0)
        return false;
    if(arr[0] == value)
        return true;
    else    
        return isPresent(arr+1, size-1, value);
    
}

int main(){
    int arr[5] = {1,2,3,6,4};
    int value;
    cin >> value;
    cout << isPresent(arr, 5, value) << endl;
    return 0;
}