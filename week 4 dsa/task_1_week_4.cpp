#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    head->data = 10;
    second->data = 20;
    head->next = second;
    second->next = NULL;
    cout << "Datas :" << head->data << " " << second->data << endl;
    cout << "Addresses :" << head->next << " " << second->next << endl;
    return 0;
}