
#include <iostream>
#include "Student.h"

using namespace std;

int Student::totalStudents = 0;

Student::Student(int studentID, const char name[], int semester, double cgpa)
    : studentID(studentID)
{
    int i = 0;

    while (name[i] != '\0' && i < 49)
    {
        this->name[i] = name[i];
        i++;
    }

    this->name[i] = '\0';

    this->semester = semester;
    this->cgpa = cgpa;

    totalStudents++;
}

void Student::display() const
{
    cout << "Student ID" << studentID << endl;
    cout << "Name" << name << endl;
    cout << "Semester" << semester << endl;
    cout << "CGPA" << cgpa << endl;
}

void Student::updateInfo(const char name[], int semester, double cgpa)
{
    int i = 0;

    while (name[i] != '\0' && i < 49)
    {
        this->name[i] = name[i];
        i++;
    }

    this->name[i] = '\0';

    this->semester = semester;
    this->cgpa = cgpa;
}

void Student::showTotalStudents()
{
    cout << "Total Registered Students" << totalStudents << endl;
}

void displayStudent(Student* ptr)
{
    if (ptr != nullptr)
    {
        ptr->display();
    }
}

int Student::getStudentID() const
{
    return studentID;
}