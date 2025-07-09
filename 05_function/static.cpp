#include <iostream>
using namespace std;
class item {
    static int count; // static member variable
    int number; // non-static member variable
public:
    void getdata(int a) {
        number = a;
        count++;
    }
    void display() {
        cout << "Number: " << number << ", Count: " << count << endl;
    }
    void getcount() {
        cout << "Count: " << count << endl;
    }
};
int item::count; // definition of static member variable
int main() {
    item a, b, c; // creating objects
    a.getcount(); // static member function can be called without an object
    b.getcount();
    c.getcount();

    a.getdata(5); // setting data for each object
    b.getdata(10);
    c.getdata(15);

    cout << "After reading data:" << endl;

    a.getcount(); // displaying count
    b.getcount();
    c.getcount();
    
    return 0;
}