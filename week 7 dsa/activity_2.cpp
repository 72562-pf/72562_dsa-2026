#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {40, 10, 50, 20, 30};
    int minIndex, temp;
    for (int i = 0; i < 4; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout << " Order: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}