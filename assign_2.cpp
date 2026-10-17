#include <iostream>
#include <string>
using namespace std;

struct Patient { int id, age; string name, disease; };

// Q1: Singly Linked List
struct SNode { Patient p; SNode* next; SNode(Patient data) : p(data), next(nullptr) {} };
class Registration {
    SNode* head = nullptr;
public:
    void add(Patient p) {
        SNode* n = new SNode(p);
        if (!head) head = n;
        else { SNode* t = head; while (t->next) t = t->next; t->next = n; }
    }
    void search(int id) {
        for (SNode* t = head; t; t = t->next)
            if (t->p.id == id) { cout << "Found: " << t->p.name << " (" << t->p.disease << ")\n"; return; }
        cout << "Not found.\n";
    }
    void remove(int id) {
        if (!head) return;
        if (head->p.id == id) { SNode* t = head; head = head->next; delete t; cout << "Removed.\n"; return; }
        for (SNode* c = head; c->next; c = c->next)
            if (c->next->p.id == id) { SNode* t = c->next; c->next = t->next; delete t; cout << "Removed.\n"; return; }
        cout << "Not found.\n";
    }
    void display() {
        for (SNode* t = head; t; t = t->next)
            cout << "ID: " << t->p.id << " | " << t->p.name << " | " << t->p.disease << "\n";
    }
};

// Q2: Doubly Linked List
struct DNode { Patient p; DNode *next, *prev; DNode(Patient data) : p(data), next(nullptr), prev(nullptr) {} };
class History {
    DNode *head = nullptr, *tail = nullptr;
public:
    void add(Patient p) {
        DNode* n = new DNode(p);
        if (!head) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
    }
    void displayForward() { for (DNode* t = head; t; t = t->next) cout << t->p.id << " - " << t->p.name << "\n"; }
    void displayReverse() { for (DNode* t = tail; t; t = t->prev) cout << t->p.id << " - " << t->p.name << "\n"; }
};

// Q3: Circular Linked List
struct CNode { Patient p; CNode* next; CNode(Patient data) : p(data), next(nullptr) {} };
class Appointments {
    CNode *head = nullptr, *curr = nullptr;
public:
    void add(Patient p) {
        CNode* n = new CNode(p);
        if (!head) { head = curr = n; head->next = head; }
        else { CNode* t = head; while (t->next != head) t = t->next; t->next = n; n->next = head; }
    }
    void display() {
        if (!head) return;
        CNode* t = head;
        do { cout << t->p.id << " - " << t->p.name << "\n"; t = t->next; } while (t != head);
    }
    void nextAppt() { if (curr) { curr = curr->next; cout << "Next: " << curr->p.name << "\n"; } }
};

// Q4: Stack ADT
struct StackNode { Patient p; StackNode* next; StackNode(Patient data) : p(data), next(nullptr) {} };
class Emergency {
    StackNode* top = nullptr;
public:
    void push(Patient p) { StackNode* n = new StackNode(p); n->next = top; top = n; }
    void pop() {
        if (!top) return;
        StackNode* t = top; cout << "Treated: " << top->p.name << "\n"; top = top->next; delete t;
    }
    void peek() { if (top) cout << "Top Case: " << top->p.name << "\n"; }
    void display() { for (StackNode* t = top; t; t = t->next) cout << t->p.id << " - " << t->p.name << "\n"; }
};

// Q5: Main Menu
int main() {
    Registration reg; History hist; Appointments appt; Emergency emg;

    // Seed initial samples
    reg.add({101, 45, "Ali", "Flu"});
    hist.add({201, 60, "Usman", "Cardiac"});
    appt.add({301, 34, "Zainab", "Checkup"});
    emg.push({401, 22, "Hamza", "Fracture"});

    int ch, sub, id, age; string name, disease;
    do {
        cout << "\n--- HOSPITAL SYSTEM ---\n1. Registration\n2. History\n3. Appointments\n4. Emergency\n5. Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "1.Add 2.Search 3.Remove 4.Display: "; cin >> sub;
            if (sub == 1) { cout << "ID Name Age Disease: "; cin >> id >> name >> age >> disease; reg.add({id, age, name, disease}); }
            else if (sub == 2) { cout << "ID: "; cin >> id; reg.search(id); }
            else if (sub == 3) { cout << "ID: "; cin >> id; reg.remove(id); } 
            else if (sub == 4) reg.display();
        } else if (ch == 2) {
            cout << "1.Add 2.Forward 3.Reverse: "; cin >> sub;
            if (sub == 1) { cout << "ID Name Age Disease: "; cin >> id >> name >> age >> disease; hist.add({id, age, name, disease}); }
            else if (sub == 2) hist.displayForward();
            else if (sub == 3) hist.displayReverse();
        } else if (ch == 3) {
            cout << "1.Add 2.Display 3.Next: "; cin >> sub;
            if (sub == 1) { cout << "ID Name Age Reason: "; cin >> id >> name >> age >> disease; appt.add({id, age, name, disease}); }
            else if (sub == 2) appt.display();
            else if (sub == 3) appt.nextAppt();
        } else if (ch == 4) {
            cout << "1.Push 2.Pop 3.Peek 4.Display: "; cin >> sub;
            if (sub == 1) { cout << "ID Name Age Condition: "; cin >> id >> name >> age >> disease; emg.push({id, age, name, disease}); }
            else if (sub == 2) emg.pop();
            else if (sub == 3) emg.peek();
            else if (sub == 4) emg.display();
        }
    } while (ch != 5);

    return 0;
}