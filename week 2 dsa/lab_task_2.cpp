#include <iostream>
using namespace std;

int main() {
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
  int *max = &arr[0];
    for (int i = 1; i < 7; i++) {
        if (arr[i] > *max) {
            max = &arr[i];
       }
    }
    cout << "The maximum: " << *max << endl;


    int *min = &arr[0];
    for (int i = 1; i < 7; i++) {
        if (arr[i] < *min) {
            min = &arr[i];
        }
    }
    cout << "The minimum: " << *min << endl;

    return 0;
}