#include <iostream>
using namespace std;
int main() {
    int size = 25;
int *arr1 = new int[size];
int *arr2 = new int[size];
for(int i = 0; i < size; i++) {
    arr1[i] = i + 1;
    arr2[i] = (i + 1) * 10;}
    cout<<"Before swapping: " << endl;
    cout<<"array 1 is: " << endl;
    for(int i = 0; i < size; i++) {
    cout <<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"array 2 is: " << endl;
    for(int i = 0; i < size; i++) {
    cout <<arr2[i]<<" ";
    }
    cout<<endl;
int *temp = arr1;
arr1 = arr2;
arr2 = temp;
cout<<"After swapping: " << endl;
    cout<<"array 1 is: " << endl;
    for(int i = 0; i < size; i++) {
    cout <<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"array 2 is: " << endl;
    for(int i = 0; i < size; i++) {
    cout <<arr2[i]<<" ";
    }
delete[] arr1;
delete[] arr2;
return 0;
}
