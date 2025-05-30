// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int arr[100], i, j, n, temp;
    // Input array size 
    cout<<"Enter number of element: ";
    cin>> n;
    //Input array elements 
    cout<<"Enter " << n << " elements: ";
    for(i=0;i<n;i++){
        cin>> arr[i];
    }
    //Bubble sort algorithm
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                //swap
                temp = arr [j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Sorted array in ascending order:"<<endl;
    for(i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    return 0;
}