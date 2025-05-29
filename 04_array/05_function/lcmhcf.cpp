#include <iostream>
using namespace std;

int gcf(int a, int b){
    if(b==0)
    return a;
    return (b, a % b);
}
int lcm(int a, int b){
    return (a * b)/ gcf(a, b);
}
int main(){
    int x, y;
    cout<< "Enter two numbers: ";
    cin>> x >> y;
    cout<< "HCF of " << x << " and " << y << " is: " << gcf(x, y) << endl;
    cout<<"LCM of " << x << " and " << y << " is: " << lcm(x, y) << endl;
    return 0;
}