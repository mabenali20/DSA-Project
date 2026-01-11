#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

// ================== Q1: Sorted Linked List ==================
struct Node {
    int data;
    Node* next;
};

class SortedLinkedList {
public:
    Node* head;

    SortedLinkedList() {
        head = NULL;
    }

    void insertSorted(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL || head->data >= value) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void printMin() {
        if (head == NULL)
            cout << "List is empty.\n";
        else
            cout << "Minimum Value: " << head->data << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

void computeAverage(SortedLinkedList& list) {
    if (list.head == NULL) return;
    int sum = 0, count = 0;
    Node* temp = list.head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    cout << "Average of Sorted List: " << (double)sum / count << endl;
}

// ================== Q2: Linked Stack ==================
struct StackNode {
    int data;
    StackNode* next;
};

class LinkedStack {
public:
    StackNode* top;

    LinkedStack() {
        top = NULL;
    }

    void push(int value) {
        StackNode* newNode = new StackNode();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        StackNode* temp = top;
        cout << "Stack Content: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void stackAverage(LinkedStack& s) {
    if (s.top == NULL) return;
    int sum = 0, count = 0;
    StackNode* temp = s.top;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    cout << "Stack Average: " << (double)sum / count << endl;
}

// ================== Q3: Doubly Linked List ==================
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyLinkedList {
public:
    DNode* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insert(int value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }
};

int getMaxRecursive(DNode* node, int maxVal) {
    if (node == NULL) return maxVal;
    if (node->data > maxVal) maxVal = node->data;
    return getMaxRecursive(node->next, maxVal);
}

// ================== MAIN & TOOLS ==================
void pauseScreen() {
    cout << "\nPress any key to continue...";
    _getch();
}

void printHeader() {
    system("cls");
    cout << "========================================\n";
    cout << "      DATA STRUCTURE PROJECT 2026       \n";
    cout << "========================================\n";
    cout << "Developed by:\n";
    cout << "  1. Mahmoud Ali Abdel Mawgoud\n";
    cout << "  2. Walid Mahfouz Alfi\n";
    cout << "  3. Ibrahim Raafat Ibrahim\n";
    cout << "========================================\n\n";
}

void runQ1() {
    cout << "--- [Running Q1: Sorted Linked List] ---\n";
    SortedLinkedList sl;
    sl.insertSorted(50);
    sl.insertSorted(10);
    sl.insertSorted(30);
    sl.insertSorted(5);
    sl.insertSorted(100);

    cout << "List Content: ";
    sl.display();
    sl.printMin();
    computeAverage(sl);
}

void runQ2() {
    cout << "--- [Running Q2: Linked Stack] ---\n";
    LinkedStack myStack;
    myStack.push(100);
    myStack.push(200);
    myStack.push(300);
    myStack.push(400);

    myStack.printStack();
    stackAverage(myStack);
}

void runQ3() {
    cout << "--- [Running Q3: Doubly Linked List (Random 1000)] ---\n";
    DoublyLinkedList dl;
    for (int i = 0; i < 1000; i++) {
        dl.insert(rand() % 10000);
    }
    if (dl.head != NULL) {
        cout << "Max Value found is: " << getMaxRecursive(dl.head, dl.head->data) << endl;
    }
}

int main() {
    srand(time(0));
    int choice;

    do {
        printHeader();
        cout << "Select a Task to Run:\n";
        cout << "  [1] Run Q1 (Sorted Linked List)\n";
        cout << "  [2] Run Q2 (Linked Stack)\n";
        cout << "  [3] Run Q3 (Doubly List & Random)\n";
        cout << "  [0] Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;
        switch (choice) {
        case 1: runQ1(); pauseScreen(); break;
        case 2: runQ2(); pauseScreen(); break;
        case 3: runQ3(); pauseScreen(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n"; pauseScreen();
        }
    } while (choice != 0);

    return 0;
}