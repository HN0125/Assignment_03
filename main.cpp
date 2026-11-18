#include <iostream>
#include "Student.h"
#include "Wallet.h"
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


void runQuestion2()
{
    int id1, id2;
    char name1[50], name2[50];
    double balance1, balance2;

    cout << "Enter details for Wallet 1" << endl;

    cout << "Wallet ID ";
    cin >> id1;

    cin.ignore(1000, '\n');

    cout << "Owner Name ";
    cin.getline(name1, 50);

    cout << "Initial Balance ";
    cin >> balance1;

    Wallet w1(id1, name1, balance1);

    cout << "Enter details for Wallet 2" << endl;

    cout << "Wallet ID ";
    cin >> id2;

    cin.ignore(1000, '\n');

    cout << "Owner Name ";
    cin.getline(name2, 50);

    cout << "Initial Balance";
    cin >> balance2;

    Wallet w2(id2, name2, balance2);

    cout << "Wallet 1 Transactions" << endl;
    w1.deposit(2000);
    w1.withdraw(1000);

    cout << "Wallet 2 Transactions" << endl;
    w2.deposit(3000);
    w2.withdraw(500);

    cout << "Wallet 1 Details" << endl;
    cout << w1;

    cout << "Wallet 2 Details" << endl;
    cout << w2;

    cout << "Comparing Wallets" << endl;
    compareWallets(w1, w2);

    cout << "Combining Wallet Balances" << endl;
    cout << "Combined Balance: Rs" << w1 + w2 << endl;

    cout << "Difference Between Wallets" << endl;
    cout << "Difference: Rs" << w1 - w2 << endl;

    cout << "Checking Equality" << endl;

    if (w1 == w2)
    {
        cout << "Wallets have equal balances" << endl;
    }
    else
    {
        cout << "Wallets do not have equal balances" << endl;
    }

    cout << "Deep Copy Demonstration" << endl;

    Wallet copiedWallet(w1);

    cout << "Adding Rs. 500 to copied wallet" << endl;
    copiedWallet.deposit(500);

    cout << "Original Wallet:" << endl;
    cout << w1;

    cout << "Copied Wallet:" << endl;
    cout << copiedWallet;

    cout << "Assignment Operator Demonstration:" << endl;

    Wallet w3(503, "Ahmed", 500);
    w3 = w1;

    cout << w3;

    Wallet::showTotalWallets();
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
