/*
Ques: Longest substring without repeating characters
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    string str = "pwwkew";
    
    //BRUTE -> Time: O(n^2) Space: O(n)
    //string s;
    // int maxLength = 0, size = 0;
    // set<char> freq;
    // for(int i=0; i<str.size(); i++)
    // {
    //     freq.insert(str[i]);
    //     for(int j=i+1; j<str.size(); j++)
    //     {
    //         if(freq.find(str[j]) == freq.end())
    //             freq.insert(str[j]);
    //         else
    //         {
    //             size = freq.size();
    //             maxLength = max(maxLength, size);
    //             break;
    //         }
    //     }
    //     freq.erase(freq.begin(), freq.end());
    // }

    //BETTER -> Time: O(2n) Space: O(n)
    // int l=0, r=0, maxLength=0;
    // set<char> freq;
    // while(r < str.size()){
    //     if(freq.count(str[r]) == 0){
    //         maxLength = max(maxLength, (r-l+1));
    //         freq.insert(str[r]);
    //         r++;
    //     }
    //     else{
    //         while(freq.count(str[l])){
    //             freq.erase(str[l]);
    //             l++;
    //         }
    //         //put str[r] in set
    //         freq.insert(str[r]);
    //         r++;
    //     }
    //     cout<<"l: "<<l<<" r: "<<r<<" max: "<<maxLength<<endl;
    // }


    //OPTIMAL -> Time: O(n) Space: O(n)
    int l=0, r=0, maxLength=0;
    map<char, int> temp;

    while(r < str.size()){
        cout<<"l:"<<l<<" r:"<<r<<endl;
        maxLength = max(maxLength, (r-l+1));
        if(temp.count(str[r]) == 0){
            // cout<<"inserting"<<endl;
            
            temp.insert({str[r], r});
            
        }
        else{
            // cout<<"changing l"<<endl;
            l = temp[str[r]]+2;
            temp[str[r]] = r;
            
        }
        r++;
        
        for(auto i: temp)
            cout << i.first << "," << i.second << endl;
        cout<<"*******************"<<endl;
    }

    

    cout<<maxLength<<endl;

    return 0;
}