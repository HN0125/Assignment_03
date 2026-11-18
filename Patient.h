#pragma once
#include <iostream>

class Patient
{
private:
    const int patientID;
    char patientName[50];
    int age;

    double* dailyCharges;
    int numberOfDays;

    static int totalPatients;

    void copyName(const char name[]);

public:
    Patient(int patientID, const char patientName[],
        int age, int numberOfDays, const double charges[]);

    Patient(const Patient& other);

    ~Patient();

    Patient& operator=(const Patient& other);

    double calculateBill() const;

    double& operator[](int index);
    const double& operator[](int index) const;

    double operator+(const Patient& other) const;

    bool operator>(const Patient& other) const;
    bool operator==(const Patient& other) const;

    Patient& operator++();
    Patient operator++(int);

    static void showTotalPatients();

    friend void compareBills(const Patient& p1, const Patient& p2);

    friend class HospitalManager;

    friend std::ostream& operator<<(std::ostream& out,
        const Patient& patient);
};

class HospitalManager
{
public:
    void generateReport(Patient* patients[], int count);
};

