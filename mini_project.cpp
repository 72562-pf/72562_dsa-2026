#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Number of subjects per student
const int NUM_SUBJECTS = 3;

// Structure to store student details
struct Student {
    int id;
    string name;
    float marks[NUM_SUBJECTS];
    float totalMarks;
    float percentage;
    char grade;
    int rank;
};

// Function Prototypes (Matching Required Operations)
void resizeArray(Student* &arr, int &capacity);
void addStudent(Student* &arr, int &n, int &capacity);
void calculateResult(Student* arr, int n);
void sortByMarks(Student* arr, int n);
void sortById(Student* arr, int n);
int searchByID(Student* arr, int n, int targetId);
void findTopStudent(Student* arr, int n);
void displayRanking(Student* arr, int n);
void updateMarks(Student* arr, int &n);

int main() {
    int capacity = 2; // Initial dynamic capacity
    int n = 0;        // Current number of students
    Student* students = new Student[capacity];

    int choice;
    do {
        cout << "\n========================================\n";
        cout << "   STUDENT RESULT & RANKING SYSTEM      \n";
        cout << "========================================\n";
        cout << "1. Add Student\n";
        cout << "2. Calculate Results (Total, %, Grade)\n";
        cout << "3. Display Ranking (Sorted by Marks)\n";
        cout << "4. Find Top Student\n";
        cout << "5. Search Student by ID (Binary Search)\n";
        cout << "6. Update Student Marks\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, n, capacity);
                break;
            case 2:
                if (n == 0) {
                    cout << "\n[!] No student records available.\n";
                } else {
                    calculateResult(students, n);
                    cout << "\n[+] Results calculated successfully for all students!\n";
                }
                break;
            case 3:
                if (n == 0) {
                    cout << "\n[!] No student records available.\n";
                } else {
                    calculateResult(students, n); // Ensure results are up-to-date
                    sortByMarks(students, n);     // Sort descending by marks & assign ranks
                    displayRanking(students, n);
                }
                break;
            case 4:
                if (n == 0) {
                    cout << "\n[!] No student records available.\n";
                } else {
                    calculateResult(students, n);
                    sortByMarks(students, n);
                    findTopStudent(students, n);
                }
                break;
            case 5: {
                if (n == 0) {
                    cout << "\n[!] No student records available to search.\n";
                    break;
                }
                
                // CRITICAL REQUIREMENT: Sort student IDs first before Binary Search
                sortById(students, n);

                int searchId;
                cout << "Enter Student ID to search: ";
                cin >> searchId;

                int index = searchByID(students, n, searchId);
                if (index != -1) {
                    cout << "\n[+] Student Found via Binary Search!\n";
                    cout << "----------------------------------------\n";
                    cout << "ID         : " << students[index].id << "\n";
                    cout << "Name       : " << students[index].name << "\n";
                    cout << "Total Marks: " << students[index].totalMarks << " / " << (NUM_SUBJECTS * 100) << "\n";
                    cout << "Percentage : " << fixed << setprecision(2) << students[index].percentage << "%\n";
                    cout << "Grade      : " << students[index].grade << "\n";
                    cout << "----------------------------------------\n";
                } else {
                    cout << "\n[!] Student with ID " << searchId << " not found.\n";
                }
                break;
            }
            case 6:
                updateMarks(students, n);
                break;
            case 7:
                cout << "\nExiting program. Cleaning up dynamic memory...\n";
                break;
            default:
                cout << "\n[!] Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    // Free dynamically allocated memory
    delete[] students;
    return 0;
}

// Function to dynamically resize the array
void resizeArray(Student* &arr, int &capacity) {
    capacity *= 2;
    Student* temp = new Student[capacity];

    for (int i = 0; i < capacity / 2; i++) {
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
    cout << "\n[Info] Dynamic array resized to capacity: " << capacity << "\n";
}

// 1. addStudent()
void addStudent(Student* &arr, int &n, int &capacity) {
    if (n >= capacity) {
        resizeArray(arr, capacity);
    }

    cout << "\nEnter Student ID: ";
    cin >> arr[n].id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, arr[n].name);

    arr[n].totalMarks = 0;
    cout << "Enter marks for " << NUM_SUBJECTS << " subjects (out of 100 each):\n";
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "  Subject " << (i + 1) << ": ";
        cin >> arr[n].marks[i];
        arr[n].totalMarks += arr[n].marks[i];
    }
    
    arr[n].percentage = (arr[n].totalMarks / (NUM_SUBJECTS * 100)) * 100.0;
    
    // Initial grade & rank placeholders
    arr[n].grade = '-';
    arr[n].rank = 0;

    n++;
    cout << "[+] Student added successfully!\n";
}

// 2. calculateResult()
void calculateResult(Student* arr, int n) {
    for (int i = 0; i < n; i++) {
        // Recalculate total and percentage in case marks were updated
        arr[i].totalMarks = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            arr[i].totalMarks += arr[i].marks[j];
        }
        arr[i].percentage = (arr[i].totalMarks / (NUM_SUBJECTS * 100)) * 100.0;

        // Assign Grade based on Percentage
        if (arr[i].percentage >= 85) {
            arr[i].grade = 'A';
        } else if (arr[i].percentage >= 70) {
            arr[i].grade = 'B';
        } else if (arr[i].percentage >= 50) {
            arr[i].grade = 'C';
        } else if (arr[i].percentage >= 40) {
            arr[i].grade = 'D';
        } else {
            arr[i].grade = 'F';
        }
    }
}

// 3. sortByMarks() (Bubble Sort descending for rankings)
void sortByMarks(Student* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].totalMarks < arr[j + 1].totalMarks) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Assign Ranks sequentially after sorting by marks
    for (int i = 0; i < n; i++) {
        arr[i].rank = i + 1;
    }
}

// Helper: sortById() (Bubble Sort ascending for Binary Search requirement)
void sortById(Student* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].id > arr[j + 1].id) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 4. searchByID() (Binary Search)
int searchByID(Student* arr, int n, int targetId) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].id == targetId) {
            return mid;
        }
        if (arr[mid].id < targetId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// 5. findTopStudent()
void findTopStudent(Student* arr, int n) {
    if (n == 0) return;
    
    // Top student is at index 0 after sortByMarks()
    cout << "\n========================================\n";
    cout << "          TOP PERFORMING STUDENT        \n";
    cout << "========================================\n";
    cout << "Name      : " << arr[0].name << "\n";
    cout << "ID        : " << arr[0].id << "\n";
    cout << "Total     : " << arr[0].totalMarks << " / " << (NUM_SUBJECTS * 100) << "\n";
    cout << "Percentage: " << fixed << setprecision(2) << arr[0].percentage << "%\n";
    cout << "Grade     : " << arr[0].grade << "\n";
    cout << "----------------------------------------\n";
}

// 6. displayRanking()
void displayRanking(Student* arr, int n) {
    cout << "\n--------------------------------------------------------------------\n";
    cout << left << setw(6) << "Rank" << setw(8) << "ID" << setw(18) << "Name" << setw(12) << "Total" << setw(12) << "%" << setw(8) << "Grade" << "\n";
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << arr[i].rank 
             << setw(8) << arr[i].id 
             << setw(18) << arr[i].name 
             << setw(12) << arr[i].totalMarks 
             << setw(12) << fixed << setprecision(2) << arr[i].percentage 
             << setw(8) << arr[i].grade << "\n";
    }
    cout << "--------------------------------------------------------------------\n";
}

// 7. updateMarks()
void updateMarks(Student* arr, int &n) {
    if (n == 0) {
        cout << "\n[!] No records available to update.\n";
        return;
    }

    int targetId;
    cout << "Enter Student ID whose marks you want to update: ";
    cin >> targetId;

    // We can use sequential scan or sort/binary search to find the record to update
    int foundIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].id == targetId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "\n[!] Student with ID " << targetId << " not found.\n";
        return;
    }

    cout << "Current marks for " << arr[foundIndex].name << ":\n";
    arr[foundIndex].totalMarks = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "  New Marks for Subject " << (i + 1) << " (current: " << arr[foundIndex].marks[i] << "): ";
        cin >> arr[foundIndex].marks[i];
        arr[foundIndex].totalMarks += arr[foundIndex].marks[i];
    }

    // Recalculate results immediately
    calculateResult(arr, n);
    cout << "\n[+] Marks updated and results recalculated successfully!\n";
}