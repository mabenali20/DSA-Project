/*

Q2-Write c++ program to implement linked stack using pointer, then add the following:-
A) Add non-member function to compute the average for all values without removing its elements.
B) Add Member Function to print the values for the Stack.

*/

#include "LinkedStack.h"
#include <iostream>

using namespace std;

LinkedStack::LinkedStack() {
    top = nullptr;
}

LinkedStack::~LinkedStack() {
    StackNode* current = top;
    while (current != nullptr) {
        StackNode* next = current->next;
        delete current;
        current = next;
    }
}

// الـ Push في الـ Stack دايماً في الأول (O(1))
void LinkedStack::push(int value) {
    StackNode* newNode = new StackNode;
    newNode->data = value;
    newNode->next = top; // الجديد بيشاور على القديم
    top = newNode;       // الجديد بقى هو القمة
}

void LinkedStack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow (Empty)" << endl;
        return;
    }
    StackNode* temp = top;
    top = top->next; // حرك القمة للي تحته
    delete temp;     // امسح اللي كان فوق
}

void LinkedStack::display() {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    StackNode* temp = top;
    cout << "Stack Content (Top -> Bottom): ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

StackNode* LinkedStack::getTop() {
    return top;
}

// دالة المتوسط بدون حذف العناصر (مطلوب A)
double stackAverage(StackNode* top) {
    if (top == nullptr) return 0.0;

    double sum = 0;
    int count = 0;
    // بنستخدم مؤشر مؤقت عشان الـ top الأصلي ميتغيرش
    StackNode* temp = top;

    while (temp != nullptr) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    return sum / count;
}