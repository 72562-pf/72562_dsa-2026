#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;

    first->data = 10;
    second->data = 80;
    third->data = 30;

    first->next = second;
    second->next = third;
    third->next = first;

    cout << first->data << " ";
    cout << first->next->data << " ";
    cout << second->next->next->data;

    return 0;
}