#include <iostream>
using namespace std;

int main() {
    int arr[7];
    int *p = arr;
    int search;

    cout << "Enter 7 num: ";
    for (int i = 0; i < 7; i++) {
        cin >> *(p + i);
    }

    cout << "Enter number to find index value: ";
    cin >> search;
    cout << arr[search] << endl;


    //for (int i = 0; i < 7; i++) {
        //if (*(p + i) == search) {
          //  cout << "Index is: " << i << endl;
          //  return 0; 
     //   }
    //}
    if (arr[search] != search) {
    cout << "Number not found" << endl;
}
    return 0;
}