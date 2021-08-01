/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "stackArray.h"
using namespace std;

bool isValid(string s);
int main(){
    class StackArray stack;
    string s;
    cout<<"Enter String:";
    cin>>s;
    cout<<"String:"<<s<<endl;
    // bool isValid = true;
    // for(int i=0; i<s.length(); i++){
    //     if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
    //        //opening bracket -> push to stack
    //        stack.push(s[i]);
    //     }
    //     else{
    //         //closing bracket
    //         if(stack.isEmpty())
    //             isValid = false;
    //         else{
    //             char c = char(stack.peek());
    //             stack.pop();
    //             if((c=='(' && s[i]==')') || (c=='[' && s[i]==']') || (c=='{' && s[i]=='}'))
    //                 isValid = true;
    //             else
    //                 isValid = false;
    //         }
    //     }
    // }
    // if(!stack.isEmpty()) 
    //     isValid=false;
    // cout<<"Valid: "<<isValid<<endl;
    cout<<isValid(s)<<endl;
    return 0;
}
bool isValid(string s) {
    stack<char> stack;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
           //opening bracket -> push to stack
           stack.push(s[i]);
        }
        else{
            //closing bracket
            if(stack.empty())
                return false;
            else{
                char c = char(stack.top());
                stack.pop();
                if((c=='(' && s[i]==')') || (c=='[' && s[i]==']') || (c=='{' && s[i]=='}'))
                    continue;
                else    
                    return false;
            }
        }
    }
    if(!stack.empty())
        return false;
    else
        return true;           
}