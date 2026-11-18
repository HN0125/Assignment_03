#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Wallet.h"
#include "Product.h"
#include "Patient.h"
using namespace std;


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

        cout << "Enter details for Student " << i + 1 << " " << endl;

        cout << "Student ID ";
        cin >> id;

        cout << "Name ";
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



void runQuestion3()
{
    int count;

    cout << "\nEnter number of products ";
    cin >> count;

    if (count < 1 || count > 50)
    {
        cout << "Invalid number of products" << endl;
        return;
    }

    Product* products[50];

    for (int i = 0; i < count; i++)
    {
        int id, quantity;
        char name[50], category[30];
        double price;

        cout << "Enter details for Product " << i + 1 << endl;

        cout << "Product ID ";
        cin >> id;

        cin.ignore(1000, '\n');

        cout << "Product Name ";
        cin.getline(name, 50);

        cout << "Category ";
        cin.getline(category, 30);

        cout << "Price ";
        cin >> price;

        cout << "Quantity ";
        cin >> quantity;

        products[i] = new Product(id, name, category, price, quantity);
    }

    double minimum, maximum;

    cout << "Enter minimum price ";
    cin >> minimum;

    cout << "Enter maximum price ";
    cin >> maximum;

    cout << "Products within the specified price range"
        << endl;

    for (int i = 0; i < count; i++)
    {
        if (products[i]->getPrice() >= minimum &&
            products[i]->getPrice() <= maximum)
        {
            cout << *products[i];
        }
    }

    int searchID;
    bool found = false;

    cout << "Enter Product ID to search ";
    cin >> searchID;

    for (int i = 0; i < count; i++)
    {
        if (products[i]->getProductID() == searchID)
        {
            cout << "Product Found" << endl;
            cout << *products[i];
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Product not found" << endl;
    }

    int updateID, amount;
    Product* selectedProduct = nullptr;

    cout << "Updating Stock" << endl;

    cout << "Enter Product ID ";
    cin >> updateID;

    for (int i = 0; i < count; i++)
    {
        if (products[i]->getProductID() == updateID)
        {
            selectedProduct = products[i];
            break;
        }
    }

    if (selectedProduct != nullptr)
    {
        cout << "Enter quantity to add ";
        cin >> amount;

        updateProductStock(selectedProduct, amount);

        cout << "Updated Stock" << endl;
        cout << *selectedProduct;
    }
    else
    {
        cout << "Product not found" << endl;
    }

    ResourceManager manager;
    manager.displayInventory(products, count);

    if (count >= 2)
    {
        cout << "Operator Demonstration" << endl;

        if (*products[0] == *products[1])
        {
            cout << "Both products have the same ID" << endl;
        }
        else
        {
            cout << "Products have different IDs" << endl;
        }

        if (*products[0] > *products[1])
        {
            cout << "First product is more expensive" << endl;
        }
        else
        {
            cout << "Second product is more expensive or prices are equal"
                << endl;
        }

        cout << "Combined stock (only if IDs match) "
            << *products[0] + *products[1] << endl;
    }

    if (count >= 1)
    {
        cout << "Prefix Increment Demonstration" << endl;
        ++(*products[0]);
        cout << *products[0];

        cout << "Postfix Increment Demonstration" << endl;
        (*products[0])++;
        cout << *products[0];
    }

    Product::showTotalProducts();

    for (int i = 0; i < count; i++)
    {
        delete products[i];
    }
}



void runQuestion4()
{
    int count;

    cout << "\nEnter the number of patients: ";
    cin >> count;

    if (count < 1 || count > 50)
    {
        cout << "Invalid number of patients." << endl;
        return;
    }

    Patient* patients[50];

    for (int i = 0; i < count; i++)
    {
        int id, age, days;
        char name[50];

        cout << "\nEnter details for Patient " << i + 1 << ":" << endl;

        cout << "Patient ID: ";
        cin >> id;

        cin.ignore(1000, '\n');

        cout << "Name: ";
        cin.getline(name, 50);

        cout << "Age: ";
        cin >> age;

        cout << "Number of treatment days: ";
        cin >> days;

        if (days < 1 || days > 365)
        {
            cout << "Invalid number of days." << endl;

            for (int j = 0; j < i; j++)
            {
                delete patients[j];
            }

            return;
        }

        double* charges = new double[days];

        cout << "\nEnter daily treatment charges:" << endl;

        for (int j = 0; j < days; j++)
        {
            cout << "Day " << j + 1 << ": ";
            cin >> charges[j];
        }

        patients[i] = new Patient(id, name, age, days, charges);

        delete[] charges;
    }

    cout << "\nPatient Billing Report:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << "\nPatient " << i + 1 << ": "
            << patients[i]->operator[](0) * 0
            << endl;

        cout << *patients[i];
    }

    if (count >= 2)
    {
        cout << "\nComparing Patient Bills:" << endl;

        compareBills(*patients[0], *patients[1]);

        cout << "\nOperator Demonstration:" << endl;

        cout << "Combined Bill: Rs. "
            << *patients[0] + *patients[1] << endl;

        if (*patients[0] > *patients[1])
        {
            cout << "Patient 1 has a higher bill." << endl;
        }
        else
        {
            cout << "Patient 1 does not have a higher bill." << endl;
        }

        if (*patients[0] == *patients[1])
        {
            cout << "Both bills are equal." << endl;
        }
        else
        {
            cout << "Both bills are not equal." << endl;
        }
    }

    cout << "\nAccessing Daily Charges:" << endl;

    int patientNumber, dayNumber;

    cout << "Enter patient number: ";
    cin >> patientNumber;

    cout << "Enter day number: ";
    cin >> dayNumber;

    if (patientNumber >= 1 && patientNumber <= count)
    {
        double charge = (*patients[patientNumber - 1])[dayNumber - 1];

        cout << "Treatment Charge: Rs. " << charge << endl;
    }
    else
    {
        cout << "Invalid patient number." << endl;
    }

    HospitalManager manager;
    manager.generateReport(patients, count);

    Patient::showTotalPatients();

    for (int i = 0; i < count; i++)
    {
        delete patients[i];
    }
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
