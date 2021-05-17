/*
Time Complexity: O(n^2)
Space Complexity: 
*/
#include <iostream>
#include <climits>
using namespace std;

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n=sizeof(arr)/sizeof(int);
    
    /*
    int max = INT_MIN, sum=0, start, end, i, j;
    
    for(i=0; i<n; i++){
        sum = 0;
        for(j=i; j<n; j++){
            sum += arr[j];
            if(sum > max){
                start=i;
                end=j;
                max=sum;
            }
        }
    }
    */

    int max=arr[0], sum=0, start, end;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > max){
           max=sum;
           end=i;
        }
        if(sum < 0){
           sum=0;
        }
        else{
           start=i;
        }
    }

    cout<<"start: "<<start<<"\nend: "<<end<<"\nmax sum: "<<max<<endl;

    return 0;
}