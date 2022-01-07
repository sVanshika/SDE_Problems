/*
Ques: Find max and min in an array using minimum number of comparisons
Time:
Space:
*/

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr)/sizeof(arr[0]);
    int minEl = arr[0];
    int maxEl = arr[0];
    for(int i=1; i<n; i++){
        maxEl = max(maxEl, arr[i]); 
        minEl = min(minEl, arr[i]);
    }
    printf("max:%d min:%d\n", maxEl, minEl); 
    return 0;
}