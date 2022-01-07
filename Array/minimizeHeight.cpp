/*
 Ques: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
 Time complexity: O(N logN)
 Space complexity: O(1)  
*/
#include <bits/stdc++.h>
using namespace std;

/*
minimum difference
    = last element - first element
    = diff of consecutive element
1. sort the array
2. take out max element and min element
3. if a[i]-k >= 0
        we can check on consecutive elements
        max = (last element - k) or (current element + k)
        min = (first element + k) or (previous element - k)
    else
        only first and last element counts
        max = last element - k
        min = first element + k
4. take out max difference 
5. loop - step 3 and step 4
*/

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr+n);
        
    int maxElement = arr[n-1];
    int minElement = arr[0];
    int diff = maxElement - minElement;
    for(int i=1; i<n; i++){
        if(arr[i]-k >=0){
            cout<<"non negative ";
            minElement = min(arr[0]+k, arr[i]-k);
            maxElement = max(arr[n-1]-k, arr[i-1]+k);
        }
        else{
            cout<<"negative ";
            minElement = arr[0];
            maxElement = arr[n-1];
        }
                
        printf("max:%d min:%d\n", maxElement, minElement);
        diff = min(diff, maxElement-minElement);
    }
        
    return diff;
}

int main(){
    int n,k;
    cout<<"n:";
    cin>>n;
    cout<<"k:";
    cin>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"-";
        cin>>arr[i];
    }
    cout<<getMinDiff(arr, n, k)<<endl;
    return 0;
}