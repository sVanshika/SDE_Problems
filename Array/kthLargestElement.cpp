/*
Ques: Find out the kth largest element in an array 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 Approach: Build *priority queue* (by default max heap)
 pop out k times to have kth largest element
 Time: O(n) + O(k.logk)
*/
int kthLargest( vector<int> arr, int n, int k){
    // by default -> max heap
    priority_queue<int> pq;

    for(int i:arr)
        pq.push(i); //pushing n elements

    for(int i=0; i<k-1; i++)
        pq.pop(); //popping k-1 elements
    
    return pq.top();
}
int main(){
    vector<int> arr = {5, 7, 11, 9, 1, 13};
    int k = 3;
    int ans = kthLargest(arr, arr.size(), k);
    cout << ans << endl;
    return 0;
}