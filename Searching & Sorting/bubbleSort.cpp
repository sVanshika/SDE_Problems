/*
Time Complexity: O(n^2)
Space Complexity: 
*/
#include <iostream>
using namespace std;

int main(){
    int a[] = {2,1,8,3,5,9,10}, n=sizeof(a)/sizeof(int);
    bubblesort(a, n);
    for(int i:a)
        cout<<i<<" ";   
    return 0;
}
