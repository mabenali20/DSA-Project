/*

Q3) Write c++ program to implement the doubly linked list using pointer, Then
A) Write a C++ program to make a list of 1000 item and fill the list
With 1000 random value.
B) Add a non-member recursive function getMax to return the maximum value from the values inside
the list.

*/

#include "DoublyList.h"
#include <iostream>
#include <cstdlib> // عشان دالة rand()
#include <ctime>   // عشان الوقت للـ Random

using namespace std;

DoublyList::DoublyList() {
    head = nullptr;
    tail = nullptr;
}

// دالة إضافة عادية في الآخر
void DoublyList::append(int value) {
    DoublyNode* newNode = new DoublyNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode; // القديم بيشاور عالجديد
        newNode->prev = tail; // الجديد بيشاور عالقديم
        tail = newNode;       // الجديد بقى هو الديل
    }
}

// دالة تعبئة القائمة بأرقام عشوائية
void DoublyList::generateRandomList(int size) {
    // بنستخدم الوقت الحالي كبذرة للعشوائية عشان الأرقام تتغير كل مرة
    srand(time(0));

    for (int i = 0; i < size; i++) {
        int randomVal = rand() % 10000; // أرقام عشوائية من 0 لـ 9999
        append(randomVal);
    }
    cout << size << " random items added to the list." << endl;
}

void DoublyList::display() {
    DoublyNode* temp = head;
    int count = 0;
    // هنطبع أول 10 بس عشان الـ 1000 كتير أوي على الشاشة
    while (temp != nullptr && count < 10) {
        cout << temp->data << " <-> ";
        temp = temp->next;
        count++;
    }
    cout << "... (Rest of list)" << endl;
}

DoublyNode* DoublyList::getHead() {
    return head;
}

// -----------------------------------------------------
// دالة الـ Max Recursive (مطلوب B)
// -----------------------------------------------------
int getMaxRecursive(DoublyNode* node) {
    // 1. شرط التوقف (Base Case)
    // لو وصلنا لآخر عنصر (مفيش بعده حاجة)، يبقى هو ده الماكس بتاع نفسه
    if (node->next == nullptr) {
        return node->data;
    }

    // 2. الخطوة الريكيرسيف (Recursive Step)
    // هاتلي الماكس من باقي الليستة الأول
    int maxInRest = getMaxRecursive(node->next);

    // 3. المقارنة
    // قارن رقمي الحالي بالماكس اللي راجع من باقي الليستة
    if (node->data > maxInRest) {
        return node->data;
    }
    else {
        return maxInRest;
    }
}