/*
Ques: 
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    vector<int> a = {1,2};
    vector<int> elements;
    map<int, int> freq;

    for(int element: a){ // O(n)
        if(freq.find(element) == freq.end()) //key not found
            freq.insert({element, 1});
        else
            freq[element]++;
    }

    int n = floor(a.size()/3);

    for(auto i: freq)
        if(i.second > n)
            elements.push_back(i.first);
    
    for(int i: elements)
        cout<<i<<" ";

    return 0;
}