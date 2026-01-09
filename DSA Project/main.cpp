#include <iostream>
#include <cstdlib> // عشان أوامر تنظيف الشاشة والألوان
#include "SortedList.h"
#include "LinkedStack.h"
#include "DoublyList.h"

using namespace std;

// دالة لمسح الشاشة (شغالة على ويندوز)
void clearScreen() {
    system("cls");
}

// دالة لتغيير لون الخط (أخضر هكرز مثلاً :D)
void setTheme() {
    system("color 0A"); // 0 = خلفية سوداء، A = خط أخضر فاتح
}

// دالة توقف الشاشة لحد ما المستخدم يدوس إنتر
void pauseScreen() {
    cout << "\nPress Enter to return to menu...";
    cin.ignore();
    cin.get();
}

void showHeader() {
    cout << "==========================================" << endl;
    cout << "      DATA STRUCTURE PROJECT 2026         " << endl;
    cout << "==========================================" << endl;
    cout << "Developed by:" << endl;
    cout << "  1. Mahmoud Ali Abdel Mawgoud" << endl;
    cout << "  2. Walid Mahfouz El-Fay" << endl;
    cout << "  3. Ibrahim Raafat Ibrahim" << endl;
    cout << "==========================================" << endl;
    cout << endl;
}

// دالة تنفيذ السؤال الأول
void runQ1() {
    clearScreen();
    cout << ">>> RUNNING Q1: SORTED LINKED LIST <<<" << endl;
    cout << "--------------------------------------" << endl;

    SortedList list;
    cout << "[Step 1] Inserting: 50, 10, 30, 5, 100..." << endl;
    list.insert(50);
    list.insert(10);
    list.insert(30);
    list.insert(5);
    list.insert(100);

    cout << "[Step 2] Displaying Sorted List:" << endl;
    list.display();

    cout << "[Step 3] Member Function (Min Value): ";
    list.printMin();

    cout << "[Step 4] Non-Member Function (Average): " << computeAverage(list.getHead()) << endl;
}

// دالة تنفيذ السؤال الثاني
void runQ2() {
    clearScreen();
    cout << ">>> RUNNING Q2: LINKED STACK <<<" << endl;
    cout << "--------------------------------" << endl;

    LinkedStack stack;
    cout << "[Step 1] Pushing: 10, 20, 30, 40..." << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40); // ده آخر واحد دخل

    cout << "[Step 2] Displaying Stack (LIFO):" << endl;
    stack.display();

    cout << "[Step 3] Calculating Average (without removing elements)..." << endl;
    double avg = stackAverage(stack.getTop());
    cout << "Average Value: " << avg << endl;

    cout << "[Step 4] Verifying Stack Integrity:" << endl;
    stack.display();
}

// دالة تنفيذ السؤال الثالث
void runQ3() {
    clearScreen();
    cout << ">>> RUNNING Q3: DOUBLY LIST (RANDOM & RECURSION) <<<" << endl;
    cout << "----------------------------------------------------" << endl;

    DoublyList dList;
    int size = 1000;

    cout << "[Step 1] Generating " << size << " random numbers..." << endl;
    dList.generateRandomList(size);

    cout << "[Step 2] Showing first 10 elements preview:" << endl;
    dList.display();

    cout << "[Step 3] Finding Maximum Value using Recursion..." << endl;
    cout << "(Calculating...)" << endl;
    int maxVal = getMaxRecursive(dList.getHead());
    cout << ">>> MAX VALUE IS: " << maxVal << endl;
}

int main() {
    setTheme(); // تظبيط الألوان أول ما البرنامج يفتح
    int choice = 0;

    while (true) {
        clearScreen();
        showHeader();
        cout << "Select a Task to Run:" << endl;
        cout << " [1] Run Q1 (Sorted Linked List)" << endl;
        cout << " [2] Run Q2 (Linked Stack)" << endl;
        cout << " [3] Run Q3 (Doubly List & Random)" << endl;
        cout << " [0] Exit" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            runQ1();
            pauseScreen();
            break;
        case 2:
            runQ2();
            pauseScreen();
            break;
        case 3:
            runQ3();
            pauseScreen();
            break;
        case 0:
            cout << "\nGoodbye Engineer Mahmoud!" << endl;
            return 0;
        default:
            cout << "\nInvalid choice! Try again." << endl;
            pauseScreen();
        }
    }

    return 0;
}