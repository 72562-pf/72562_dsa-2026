#include <iostream>
using namespace std;
int main() {
    int arr[5] = {15, 24, 39, 42, 58};
    int target;
    bool found = false;
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter number to search: ";
    cin >> target;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == target) {
            cout << "Number " << target << " found at index: " << i << endl;
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Number " << target << " array me nahi mila." << endl;
    }

    return 0;
}
//array min and max value find karne ka code