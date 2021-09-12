/*
Ques: Find the majority element that occurs more than floor(n/2) times
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int a[] = {5,5,1,2,5,2};

    // ** Moore's Voting Algo -> Time: O(n) Space: O(1)
    int count=0, element;
    for(int i: a){
        if(count == 0)
            element = i;
        if(element == i)
            count++;
        else   
            count--;
    }
    cout<<element<<endl;
    

    // ** Time:O(2n) Space:O(n) **
    // map<int, int> freq;
    // for(int element: a){ // O(n)
    //     if(freq.find(element) == freq.end()) //key not found
    //         freq.insert({element, 1});
    //     else
    //         freq[element]++;
    // }

    // int max=freq.begin()->second, element=freq.begin()->first;
    
    // for(auto i: freq){
    //     if(i.second > max){
    //         element = i.first;
    //         max = i.second;
    //     }
    // }
    // cout << "max:" << max << "element:" << element << endl;

   
    return 0;
}