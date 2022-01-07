/*
Ques: 
Time Complexity: 
Space Complexity: 
*/
#include <bits/stdc++.h>

using namespace std;

bool checkCongurrent(string a, string b){
    if (a == b)
        return true;
    
    int len_a = a.length();
    int len_b = b.length();

    if (len_a == len_b){
        // replace can happen
        int count=0;
        for(int i=0; i<len_a; i++){
            if(a[i] != b[i])
                count++;
        }
        if (count == 1)
            return true;
    }

    else if (abs(len_a - len_b) == 1){
        // add or remove can happen
        if (strstr(a.c_str(), b.c_str()) || strstr(b.c_str(), a.c_str()))
            return true;
    }

    return false;

}
int main(){
    int n;
    string a, b;
    cin >> n;
    
    int len_a, len_b;
    for(int i=0; i<n; i++)
        cin >> a >> b;
        cout << checkCongurrent(a, b) << endl;
        

    return 0;
}