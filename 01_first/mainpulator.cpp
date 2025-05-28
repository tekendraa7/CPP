#include <iostream>
#include <iomanip>
using namespace std;
int main (){
    int a = 100, b = 40000, c = 23;
    cout << "The value of a without setw is: " << a << b << c <<endl;
   

    cout << "The value of a with setw(10) is: " << setw(10) << a << endl; // setw is used to set the width of the output field
    cout << "The value of b with setw(10) is: " << setw(10) << b << endl;
    cout << "The value of c with setw(10) is: " << setw(10) << c << endl;

    cout << "The value of a with setw(10) and setfill('*') is: " << setfill('*') << setw(10) << a << endl; // setfill is used to fill the empty spaces with a specified character
    cout << "The value of b with setw(10) and setfill('*') is: " << setfill('*') << setw(10) << b << endl;
    cout << "The value of c with setw(10) and setfill('*') is: " << setfill('*') << setw(10) << c << endl;
    return 0;
}
