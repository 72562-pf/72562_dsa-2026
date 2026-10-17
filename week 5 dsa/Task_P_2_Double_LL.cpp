#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    Node* head;

public:

    DoublyLinkedList()
    {
        head = NULL;
    }

    void append(int value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;

            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
    }

    void display()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Doubly Linked List: ";

    list.display();

    return 0;
}