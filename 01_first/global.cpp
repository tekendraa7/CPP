// This code is about how to access global variables in C++.
#include <iostream>
using namespace std;
int sum = 10; // Global variable
int main() {
    int a, b, sum;
    cout <<"Enter the value of a:" << endl; // << endl; // endl is used to flush the output buffer
    cin >> a;
    cout << "Enter the value of b:\n";
    cin >> b;
    sum = a + b; // Local variable sum
    cout << "The sum is :" << sum << endl; // Output the local sum
    cout << "The global variable sum is :" << ::sum << endl; // Accessing the global variable using scope resolution operator
    return 0; 
}