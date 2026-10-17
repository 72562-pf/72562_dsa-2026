#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int items[MAX_SIZE] = {10, 20, 30, 40, 50}; 
int size = 5;

void delete_element() {
    int position;
    cout << "Enter the position you want to delete (1 to " << size << "): ";
    cin >> position;

    if (position >= 1 && position <= size) {
        
        for (int i = position - 1; i < size - 1; i++) {
            items[i] = items[i + 1];
        }
        size--; 
        cout << "Element deleted successfully.\n";
    } else {
        cout << "Invalid position!\n";
    }
}

void print_array() {
    cout << "Current elements: ";
    for (int i = 0; i < size; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    print_array();
    delete_element();
    print_array();

    return 0;
}