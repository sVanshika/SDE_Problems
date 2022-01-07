#include <iostream>
using namespace std;

bool isSorted(int arr[], int size, int index){
    if(size == 0 || size == 1)
        return true;
    if(index == size)
        return true;
    if(arr[index-1] > arr[index]){
        cout<<index<<endl;
        return false;
    }
    return isSorted(arr, size, index+1);
}

bool isSorted2(int arr[], int size){
    if (size==0 || size==1)
        return true;
    if (arr[0] > arr[1])
        return false;
    return isSorted2(arr+1, size-1);
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;

    // cout << isSorted(arr, size, 1) << endl;
    cout << isSorted2(arr, size) << endl;
    return 0;
}