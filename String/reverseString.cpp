/*
Ques: Reverse a string
Time Complexity: O(n/2)
Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    cout<<"Enter String:";
    cin>>str;
    int len = str.length();
    char temp;

    //replace ith character with (len-i-1)th character
    for(int i=0; i<(len/2); i++){
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }

    cout<<"Reverse: "<<str<<endl;
    return 0;
}