#include "Patient.h"
#include <iostream>
using namespace std;

int Patient::totalPatients = 0;

void Patient::copyName(const char name[])
{
    int i = 0;

    while (name[i] != '\0' && i < 49)
    {
        patientName[i] = name[i];
        i++;
    }

    patientName[i] = '\0';
}

Patient::Patient(int patientID, const char patientName[],
    int age, int numberOfDays, const double charges[])
    : patientID(patientID)
{
    copyName(patientName);

    this->age = age;
    this->numberOfDays = numberOfDays;

    if (numberOfDays > 0)
    {
        dailyCharges = new double[numberOfDays];

        for (int i = 0; i < numberOfDays; i++)
        {
            dailyCharges[i] = charges[i];
        }
    }
    else
    {
        dailyCharges = nullptr;
        this->numberOfDays = 0;
    }

    totalPatients++;
}

Patient::Patient(const Patient& other)
    : patientID(other.patientID)
{
    copyName(other.patientName);

    age = other.age;
    numberOfDays = other.numberOfDays;

    if (numberOfDays > 0)
    {
        dailyCharges = new double[numberOfDays];

        for (int i = 0; i < numberOfDays; i++)
        {
            dailyCharges[i] = other.dailyCharges[i];
        }
    }
    else
    {
        dailyCharges = nullptr;
    }

    totalPatients++;
}

Patient::~Patient()
{
    delete[] dailyCharges;
    totalPatients--;
}

Patient& Patient::operator=(const Patient& other)
{
    if (this != &other)
    {
        double* temp = nullptr;

        if (other.numberOfDays > 0)
        {
            temp = new double[other.numberOfDays];

            for (int i = 0; i < other.numberOfDays; i++)
            {
                temp[i] = other.dailyCharges[i];
            }
        }

        delete[] dailyCharges;

        dailyCharges = temp;
        numberOfDays = other.numberOfDays;

        copyName(other.patientName);
        age = other.age;

    }

    return *this;
}

double Patient::calculateBill() const
{
    double total = 0;

    for (int i = 0; i < numberOfDays; i++)
    {
        total += dailyCharges[i];
    }

    return total;
}

double& Patient::operator[](int index)
{
    if (index < 0 || index >= numberOfDays)
    {
        std::cout << "Invalid day number." << std::endl;

        static double invalidCharge = 0;
        invalidCharge = 0;

        return invalidCharge;
    }

    return dailyCharges[index];
}

const double& Patient::operator[](int index) const
{
    if (index < 0 || index >= numberOfDays)
    {
        static double invalidCharge = 0;
        invalidCharge = 0;

        return invalidCharge;
    }

    return dailyCharges[index];
}

double Patient::operator+(const Patient& other) const
{
    return calculateBill() + other.calculateBill();
}

bool Patient::operator>(const Patient& other) const
{
    return calculateBill() > other.calculateBill();
}

bool Patient::operator==(const Patient& other) const
{
    return calculateBill() == other.calculateBill();
}

Patient& Patient::operator++()
{
    for (int i = 0; i < numberOfDays; i++)
    {
        dailyCharges[i] += 100;
    }

    return *this;
}

Patient Patient::operator++(int)
{
    Patient temp(*this);

    for (int i = 0; i < numberOfDays; i++)
    {
        dailyCharges[i] += 100;
    }

    return temp;
}

void Patient::showTotalPatients()
{
    std::cout << "Total Registered Patients: "
        << totalPatients << std::endl;
}

void compareBills(const Patient& p1, const Patient& p2)
{
    if (p1.calculateBill() > p2.calculateBill())
    {
        std::cout << p1.patientName
            << " has the higher treatment bill." << std::endl;
    }
    else if (p2.calculateBill() > p1.calculateBill())
    {
        std::cout << p2.patientName
            << " has the higher treatment bill." << std::endl;
    }
    else
    {
        std::cout << "Both patients have equal treatment bills."
            << endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
    out << "Patient ID: " << patient.patientID;
    out << "Name: " << patient.patientName;
    out << "Age: " << patient.age;
    out << "Number of Treatment Days: " << patient.numberOfDays;

    out << "Daily Treatment Charges:" << std::endl;

    for (int i = 0; i < patient.numberOfDays; i++)
    {
        out << "Day " << i + 1
            << " Rs. " << patient.dailyCharges[i] << std::endl;
    }

    out << "Total Bill Rs. "
        << patient.calculateBill() << std::endl;

    return out;
}

void HospitalManager::generateReport(Patient* patients[], int count)
{
    std::cout << "Complete Hospital Report:" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << "Patient: " << patients[i]->patientName;
        std::cout << "Patient ID: " << patients[i]->patientID;
        std::cout << "Age: " << patients[i]->age;

        std::cout << "Total Bill: Rs. "
            << patients[i]->calculateBill() << endl;
    }
}
