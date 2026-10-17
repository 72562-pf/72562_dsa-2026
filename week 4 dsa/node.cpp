#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
int main()
{
	node* head= new node;
	node* second= new node;
	node* third= new node;
	
	head->data = 10;
	head->next = second;
	second->next =third;
	
	second->data = 20;
	second->next= third;
	
	third->data =30;
	third->next = NULL;
	
	cout<<head->data<<endl;
	cout<<head->next<<endl;
	
	cout<<second->data<<endl;
	cout<<second->next<<endl;
	
	cout<<third->data<<endl;
	cout<<third->next<<endl;
	
	return 0;
}
