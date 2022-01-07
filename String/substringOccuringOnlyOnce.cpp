/*
Ques: find the substring occuring only once
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main(){
    
    string s = "zyzyzyz";
    string substring;
    int len = s.length();
    map<string, int> substringFreq;

    for(int i=0; i<len; i++){
        for(int j=1; j<=len-i; j++){
            substring = s.substr(i, j);
            if(substringFreq.find(substring) != substringFreq.end())
                substringFreq[substring]++ ;
            else    
                substringFreq.insert({substring, 1});
        }
    }
    
    map<string, int> :: iterator itr;
    int minLength = INT_MAX;
    int l=0;
    string result;

    for(itr=substringFreq.begin(); itr != substringFreq.end(); itr++){
        l = (itr->first).length();
        if (l < minLength && (itr->second)==1){
            minLength = l;
            result = itr->first;
        }
    }

    cout << result << endl;


    return 0;
}