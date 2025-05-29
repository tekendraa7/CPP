#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    int i=0, a[] = {1,2,3,4,5,6,7,8,9,10,11};
    do {
        cout<<"The arrays are: " << a[i] <<endl;
        i++;
    } while(i<11);
    return 0;
}