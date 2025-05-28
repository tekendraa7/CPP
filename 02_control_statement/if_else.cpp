#include <iostream>
using namespace std;

int main (){
    int age;
    cout<<"Enter your age: " << endl;
    cin >> age;
    if (age < 18) {
        cout << "You are a kid." << endl;
    } else if (age == 18) {
        cout << " You can get the kid pass." << endl;
    }
    else{
        cout <<"You can join the party." << endl;
    }
    cout << "Thank you for your input!" << endl;
    return 0;
    
}
