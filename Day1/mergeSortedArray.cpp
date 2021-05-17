/*
Time complexity = O(n1 x n2//) = O(n^2)
Space complexity = O(1)
*/
#include <iostream>
using namespace std;

int main(){
    int a[] = {1,4,7,8,10}, n1=5;
    int b[] = {2,3,9}, n2=3;

    int cur=0, temp=0, x=1;

    while(cur < n1){
        if(a[cur] > b[0]){
            //swapping a[cur] and b[0]
            temp = b[0];
            b[0] = a[cur];
            a[cur] = temp;

            temp = b[0];
            
            x=1;
            //insertion sort on b
            while(b[x] < temp && x < n2){
                b[x-1] = b[x];
                x++;
            }
            b[x-1] = temp;
        }
        cur++;
    }

    for(int i: a)
        cout<<i<<" ";
    cout<<endl;
    for(int i:b)
        cout<<i<<" ";
    return 0;
}