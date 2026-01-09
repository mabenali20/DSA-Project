/*

Q1-Write c++ program to implement sorted linked list using pointer, then add the following:-
A) Add non-member function to compute the average for all values.
B) Add Member Function to print the minimum value for the list.

*/

#include "SortedList.h"
#include <iostream>

using namespace std;

SortedList::SortedList() {
    head = nullptr;
}

// Destructor to prevent memory leaks
SortedList::~SortedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SortedList::insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    // Case 1: List is empty OR new value is smaller than head
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 2: Insert somewhere in the middle or end
    Node* current = head;
    while (current->next != nullptr && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void SortedList::printMin() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    // Since list is sorted, head is always the minimum
    cout << "Minimum Value: " << head->data << endl;
}

void SortedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* SortedList::getHead() {
    return head;
}

// Non-member function implementation
double computeAverage(Node* head) {
    if (head == nullptr) return 0.0;

    double sum = 0;
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    return sum / count;
}