#include <iostream>
using namespace std;
int main (){
    int number, i = 1;
    cout <<"Enter the number to print the table:" << endl;
    cin >> number;
    // Using do-while loop to print the table of the given number
    do{
        cout<< number << " x " << i << " = " << number * i << endl;
        i++;
    } while (i <= 10);
    return 0;
}