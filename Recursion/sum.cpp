#include <iostream>
using namespace std;

int sumArray(int* arr, int size){
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[0];
    else{
        arr[1] = arr[0] + arr[1];
        return sumArray(arr+1, size-1);
    }    
}

int main(){
    int arr[5] = {10,20,30,40,50};
    cout << sumArray(arr, 5) << endl;
    return 0;
}