#include <iostream>
using namespace std;

// string rev(string s, int i, int j){
//     cout << i << " " << " " << j << " " << s << endl;
//     if(i >= j)
//         return s;
//     // swap
//     swap(s[i], s[j]);
//     return rev(s, i++, j--);
// }

void rev(string& s, int i){
    if(i >= (s.size()-1-i))
        return;
    swap(s[i], s[(s.size()-1-i)]);
    return rev(s, i+1);
}

int main(){
    string s;
    cin >> s;
    rev(s, 0);
    cout << s << endl;
    return 0;
}