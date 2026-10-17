#include <iostream>
using namespace std;

class list
{
private:
    int items[100];
    int size;

public:
    
    list() { 
        size = 0; 
    }

    int getlength() {
        return size;
    }

    void add() {
    	int value;
    cout<<"the size of array:";
    cin>>size;
		cout<<"enter the value:";
    for(int i=0;i<size;i++){
    	cin>>items[i];
    	
}
		
        
        }
    

    void delete_element() {
    	int position;
    	cout<<"enter the position:";
    	cin>> position;
        if (position >= 0 && position <= size) {
            for (int i = position - 1; i < size - 1; i++) {
                items[i] = items[i + 1];
            }
            size--;
        } else {
            cout << "Invalid position!";
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
}; 

int main()
{
    list L;
    
    L.add();
 
    
    cout << "list = ";
    L.display();
    
    L.delete_element(); 
    
    cout << "after delete: ";
    L.display();
    
    cout << "length: " << L.getlength() << endl;
    
    return 0;
}
