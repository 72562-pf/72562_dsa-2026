#include <iostream>
#include <string>

using namespace std;

//==========================================
// Base Class: Person
// Demonstrates OOP concepts (Information Hiding & Base Class Design)
// ==========================================
class Person
{
private:
    // Encapsulated private data members to protect sensitive data
    string name;
    int id;
    int age;

public:
    // Parameterized constructor initializing attributes via an initializer list
    Person(string p_name = "", int p_id = 0, int p_age = 0)
        : name(p_name), id(p_id), age(p_age) {}

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Person() {}

    // Public getter and setter methods providing controlled access to private data
    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }

    void setName(const string &p_name) { name = p_name; }
    void setId(int p_id) { id = p_id; }
    void setAge(int p_age) { age = p_age; }

    // Virtual display method to enable runtime polymorphism
    virtual void display() const
    {
        cout << "Name: " << name << " | ID: " << id << " | Age: " << age;
    }
};

// ==========================================
// Derived Class: Patient
// Inherits from Person and adds specific clinical attributes
// ==========================================
class Patient : public Person
{
private:
    string disease;
    int roomNumber;

public:
    // Constructor passing general details to Person base constructor and initializing Patient specific fields
    Patient(string p_name = "", int p_id = 0, int p_age = 0, string p_disease = "", int p_room = 0)
        : Person(p_name, p_id, p_age), disease(p_disease), roomNumber(p_room) {}

    // Getter and setter methods for Patient attributes
    string getDisease() const { return disease; }
    int getRoomNumber() const { return roomNumber; }

    void setDisease(const string &p_disease) { disease = p_disease; }
    void setRoomNumber(int p_room) { roomNumber = p_room; }

    // Overridden display method matching the exact target assignment output format
    void display() const override
    {
        // Invokes base class fields, then displays disease and room number details
        cout << "Name: " << getName()
             << " | ID: " << getId()
             << " | Age: " << getAge()
             << " | Disease: " << disease
             << " | Room: " << roomNumber << endl;
    }
};

// ==========================================
// List ADT Implementation: PatientList (Dynamic Container)
// Dynamically resizes array memory using new/delete operations
// ==========================================
class PatientList
{
private:
    Patient *array; // Pointer pointing to dynamically allocated array of Patients on heap
    int capacity;   // Current total allocated memory capacity of the array
    int count;      // Current total number of stored Patient elements

    // Helper method to resize the dynamic dynamic container when capacity is full
    void resize()
    {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2; // Double capacity when limit reached
        Patient *newArray = new Patient[newCapacity];         // Allocate larger memory block

        // Copy existing patients into newly allocated heap array
        for (int i = 0; i < count; ++i)
        {
            newArray[i] = array[i];
        }

        delete[] array;         // Deallocate old heap memory block to avoid memory leaks
        array = newArray;       // Point internal array pointer to new dynamic block
        capacity = newCapacity; // Update capacity tracker
    }

public:
    // Default constructor allocating initial dynamic memory block
    PatientList(int initialCapacity = 2)
        : capacity(initialCapacity), count(0)
    {
        array = new Patient[capacity]; // Allocate heap array
    }

    // Destructor to clean up heap memory allocation dynamically
    ~PatientList()
    {
        delete[] array; // Free memory array when class instance goes out of scope
    }

    // Operation 1: Insert (Add Patient)
    void addPatient(const Patient &patient)
    {
        if (count >= capacity)
        {
            resize(); // Automatically grow dynamic container capacity
        }
        array[count] = patient; // Append new patient at current end index
        count++;                // Increment stored count
        cout << "Patient added successfully!\n";
    }

    // Operation 2: Search Patient by ID
    int searchPatientById(int id) const
    {
        for (int i = 0; i < count; ++i)
        {
            if (array[i].getId() == id)
            {
                return i; // Return array index position if match is found
            }
        }
        return -1; // Return -1 to indicate element not found
    }

    // Operation 3: Remove Patient by ID
    bool removePatientById(int id)
    {
        int index = searchPatientById(id); // Search for patient location index
        if (index == -1)
        {
            return false; // Return false if ID does not match any record
        }

        // Shift remaining array elements leftward to fill the blank spot
        for (int i = index; i < count - 1; ++i)
        {
            array[i] = array[i + 1];
        }
        count--; // Decrement patient count
        return true;
    }

    // Operation 4: Traverse / Display All Patients
    void displayAll() const
    {
        if (count == 0)
        {
            cout << "No patient records found." << endl;
            return;
        }

        // Sequential traversal over active patients in list
        for (int i = 0; i < count; ++i)
        {
            array[i].display(); // Display each individual patient record
        }
    }

    // Operation 5: Retrieve patient object by index
    Patient getPatient(int index) const
    {
        return array[index];
    }
};

// ==========================================
// Main Function: Console Menu Drive Interface
// Matches exact interaction requirements and output formatting
// ==========================================
int main()
{
    PatientList systemList; // Instantiate patient dynamic container object
    int choice = 0;

    // Hardcode initial pre-populated data matching the assignment assignment output example
    Patient samplePatient("ali", 543, 45, "fever", 23);
    systemList.addPatient(samplePatient);

    // Menu loop driven application
    while (true)
    {
        // Primary Menu Title Bar Display
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Remove Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Process Choice Options
        if (choice == 1)
        {
            string name, disease;
            int id, age, room;

            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Disease: ";
            cin >> disease;
            cout << "Enter Room Number: ";
            cin >> room;

            Patient newPatient(name, id, age, disease, room);
            systemList.addPatient(newPatient);
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Patient ID to remove: ";
            cin >> id;
            if (systemList.removePatientById(id))
            {
                cout << "Patient record removed successfully.\n";
            }
            else
            {
                cout << "Error: Patient with ID " << id << " not found.\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Patient ID to search: ";
            cin >> id;
            int index = systemList.searchPatientById(id);
            if (index != -1)
            {
                cout << "Patient found:\n";
                systemList.getPatient(index).display();
            }
            else
            {
                cout << "Patient with ID " << id << " not found.\n";
            }
        }
        else if (choice == 4)
        {
            // Formatted to match the pdf specified sample output header precisely
            cout << "===== Display All Patients =====\n";
            systemList.displayAll();
        }
        else if (choice == 5)
        {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        else
        {
            cout << "Invalid menu choice! Please enter a valid number (1-5).\n";
        }
    }

    return 0;
}