#include <iostream>
using namespace std;

class Queue
{
private:

    // Node of Linked List
    struct Node
    {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
    int count;

public:

    // 1. Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    // 2. Destructor
    ~Queue()
    {
        while (front != nullptr)
        {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }

    // 3. isEmpty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // 4. push - Add element at REAR
    void push(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = nullptr;

        // If queue is empty
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    // 5. pop - Remove element from FRONT
    int pop()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        Node* temp = front;

        int value = temp->data;

        front = front->next;

        // If queue becomes empty
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        count--;

        return value;
    }

    // 6. top - View FRONT element
    int top()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return front->data;
    }

    // 7. size
    int size()
    {
        return count;
    }
};


int main()
{
    Queue q;

    // Add elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.top() << endl;
    cout << "Queue size: " << q.size() << endl;

    // Remove elements
    cout << "Removed: " << q.pop() << endl;
    cout << "Removed: " << q.pop() << endl;

    cout << "Front element: " << q.top() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Is queue empty? ";

    if (q.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}