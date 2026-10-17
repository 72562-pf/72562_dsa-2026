#include <iostream>
using namespace std;
int main()
{
    int stackArray[5];
    int top = -1;
    top++;
    stackArray[top] = 10;
    top++;
    stackArray[top] = 20;
    top++;
    stackArray[top] = 30;
    cout << "Top before Pop: "
         << stackArray[top] << endl;
    top--;
    cout << "Top after Pop: "
         << stackArray[top] << endl;
    return 0;
}