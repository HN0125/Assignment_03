#include <iostream>
#include "Student.h"
using namespace std;

// No global variables: each demo creates its own objects locally.

void runQuestion1()
{
    int count;

    cout << "Enter the number of students";
    cin >> count;

    if (count <= 0 || count > 50)
    {
        cout << "Invalid number of students" << endl;
        return;
    }

    Student* students[50];

    for (int i = 0; i < count; i++)
    {
        int id, semester;
        double cgpa;
        char name[50];

        cout << "Enter details for Student " << i + 1 << ":" << endl;

        cout << "Student ID ";
        cin >> id;

        cout << "Name: ";
         cin >> ws;
        cin.getline(name, 50);

        cout << "Semester ";
        cin >> semester;

        cout << "CGPA ";
        cin >> cgpa;

        students[i] = new Student(id, name, semester, cgpa);
    }

    int searchID;
    bool found = false;

    cout << "Enter Student ID to search";
    cin >> searchID;

    for (int i = 0; i < count; i++)
    {
        if (students[i]->getStudentID() == searchID)
        {
            cout << "Student Record Found" << endl;

            displayStudent(students[i]);

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found" << endl;
    }

    Student::showTotalStudents();

    for (int i = 0; i < count; i++)
    {
        delete students[i];
    }
}

void runQuestion2() {
    cout << "Q2: Digital Wallet System - TODO" << endl;
    // TODO: deposits/withdrawals, compareWallets, operators, deep-copy demo
}

void runQuestion3() {
    cout << "Q3: Inventory Management System - TODO" << endl;
    // TODO: price-range search, stock update, ResourceManager, operators
}

void runQuestion4() {
    cout << "Q4: Hospital Billing System - TODO" << endl;
    // TODO: patients, compareBills, HospitalManager report, operators
}

int main() {
    int choice = 0;
    do {
        cout << "\n===== OOP Assignment =====\n"
             << "1. Student Registration System\n"
             << "2. Digital Wallet System\n"
             << "3. Inventory Management System\n"
             << "4. Hospital Billing System\n"
             << "0. Exit\n"
             << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: runQuestion1(); break;
            case 2: runQuestion2(); break;
            case 3: runQuestion3(); break;
            case 4: runQuestion4(); break;
            case 0: break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}
