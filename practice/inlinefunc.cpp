#include <iostream>
using namespace std;

inline int getmax(int& a, int& b){
    a=a+5;
    b=b+5;
    int c=a-b;
    return c;
}

int main(){
    int a=3, b=5;
    int ans = getmax(a,b);
    cout << ans << endl;
    return 0;
}