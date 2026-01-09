#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SortedList {
private:
    Node* head;

public:
    SortedList();
    ~SortedList(); // Destructor to clean memory

    void insert(int value);
    void printMin();
    void display();
    Node* getHead();
};

// Non-member function prototype
double computeAverage(Node* head);
