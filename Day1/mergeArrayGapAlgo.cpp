/*
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a[] = {1,4,7,8,10}, n1=5;
    int b[] = {2,3,9}, n2=3;

    int gap = ceil((n1+n2)/2);
    int i=0, j=i+gap;
    
    for(gap; gap>0; gap=ceil(gap/2)){
        //comparing in a
        for(i=0; (i+gap)<n1; i++)
            if(a[i] > a[i+gap])
                swap(a[i], a[i+gap]);

        //comparing in a and b
        j = gap>n1 ? gap-n1 : 0;
        for(j; i<n1 && j<n2; i++, j++)
            if(a[i] > b[j])
                swap(a[i], b[j]);

        //comparing in b
        for(j=0; j+gap<n2; j++)
            if(b[j] > b[j+gap])
                swap(b[j], b[j+gap]);
    }

    for(int i: a)
        cout << i << " ";
    cout<<endl;
    for(int i: b)
        cout << i << " ";

    return 0;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}