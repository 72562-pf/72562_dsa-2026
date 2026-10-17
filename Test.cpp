#include <iostream>
using namespace std;
int main() {
    char choice;
    int num1, num2, sum, average, product;
    cout << "S. Sum of num" << endl;
    cout << "A. Average of num" << endl;
    cout << "P. Product of num" << endl;
     cout << "Enter your choice: "<<endl;
    cin >> choice;
    switch (choice) {
    case 'S':
    {
        cout<<"Enter two numbers: ";
        cin>>num1>>num2;
        sum=num1+num2;
        cout<<"Sum: "<<sum<<endl;
        break;
    }
    case 'A':{
        cout<<"Enter two numbers: ";
        cin>>num1>>num2;
        average=(num1+num2)/2;
        cout<<"Average: "<<average<<endl;
        break;
        }
    case 'P':
    {
        cout<<"Enter two numbers: ";
        cin>>num1>>num2;
        product=num1*num2;
        cout<<"Product: "<<product<<endl;
        break; 
        }
        
     default:
        {
        cout<<"Invalid choice!"<<endl;
    }

 }
    return 0;
}