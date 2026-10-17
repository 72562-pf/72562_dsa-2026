#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key, low = 0, high = 4;
    int mid, pos = -1;
    cout << "Enter number: ";
    cin >> key;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            pos = mid;
            break;
        }
        else if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (pos != -1)
        cout << "Number found at index " << pos;
    else
        cout << "Number not found.";
    return 0;
}