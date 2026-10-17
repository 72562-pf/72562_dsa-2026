
#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Search(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[10], key;

    cout << "Enter 10 numbers:" << endl;
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    Sort(arr, 10);

    cout << "Sorted numbers: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";

    cout << "\nEnter number to search: ";
    cin >> key;

    int index = Search(arr, 10, key);

    if (index != -1)
        cout << "Number found at index: " << index;
    else
        cout << "Number not found.";

    return 0;
}