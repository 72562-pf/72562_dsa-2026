#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

int main()
{
    Node* first = new Node;
    Node* second = new Node;

    first->data = 10;
    second->data = 20;

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = NULL;

    cout << first->data << " ";
    cout << first->next->data;

    return 0;
}