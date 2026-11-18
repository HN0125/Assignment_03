#pragma once
class Student
{
private:
    const int studentID;
    char name[50];
    int semester;
    double cgpa;

    static int totalStudents;

public:
    Student(int studentID, const char name[], int semester, double cgpa);

    void display() const;

    void updateInfo(const char name[], int semester, double cgpa);

    static void showTotalStudents();

    int getStudentID() const;
};

void displayStudent(Student* ptr);