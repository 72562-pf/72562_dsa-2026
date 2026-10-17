#include <iostream>
using namespace std;

class Stack
{
private:
    // Node structure
    struct Node
    {
        int data;
        Node* next;
    };
    Node* topNode;
    int count;
public:

    // 1. Constructor
    Stack()
    {
        topNode = nullptr;
        count = 0;
    }
    // 2. Destructor
    ~Stack()
    {
        while (topNode != nullptr)
        {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }
    // 3. isEmpty
    bool isEmpty()
    {
        return topNode == nullptr;
    }
    // 4. push
    void push(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = topNode;

        topNode = newNode;
        count++;
    }
    // 5. pop
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        Node* temp = topNode;

        int value = temp->data;

        topNode = topNode->next;

        delete temp;

        count--;

        return value;
    }
    // 6. top
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return topNode->data;
    }
    // 7. size
    int size()
    {
        return count;
    }
};

int main()
{
    Stack s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    // Pop elements
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    cout << "Top element: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    cout << "Is stack empty? ";

    if (s.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}