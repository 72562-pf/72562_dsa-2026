#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str)
{
    char stack[100];
    int top = -1;

    // Step 1: Push every character into stack
    for (int i = 0; i < str.length(); i++)
    {
        top++;
        stack[top] = str[i];
    }

    // Step 2: Compare string with stack (reverse order)

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != stack[top])
        {
            return false;
        }

        top--;
    }

    return true;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "Result is valid" << endl;
    else
        cout << "Result is invalid" << endl;

    return 0;
}  