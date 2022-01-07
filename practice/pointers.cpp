#include <iostream>
using namespace std;

int main(){
    int i=5;
    int* ptr = &i;
    // cout << "i = " << i << endl;
    // cout << "ptr = " << ptr << endl;
    // cout << "*ptr = " << *ptr << endl;
    
    ptr = ptr + 1;
    // cout << "ptr = " << ptr << endl;
    // cout << "*ptr = " << *ptr << endl;

    double* f;
    cout << sizeof(i) << endl << sizeof(ptr) << endl << sizeof(f) << endl;

    return 0;
}