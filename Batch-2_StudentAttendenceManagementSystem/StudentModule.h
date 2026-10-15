#ifndef STUDENT_MODULE_H
#define STUDENT_MODULE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_DAYS = 30;

class Student {
private:
    string rollNumber;
    string name;
    string dates[MAX_DAYS];
    char status[MAX_DAYS];
    int attendanceCount;

public:
    Student();
    Student(string roll, string studentName);
    ~Student();

    string getRollNumber() const;
    string getName() const;

    bool hasDate(string date) const;
    void markAttendance(string date, char attendanceStatus);
    bool updateAttendance(string date, char newStatus);

    int getPresentDays() const;
    int getAbsentDays() const;
    double getPercentage() const;

    void showAttendance() const;
    void showSummary() const;
};

extern Student students[MAX_STUDENTS];
extern int studentCount;

int findStudent(string rollNumber);
bool isValidDate(string date);
string getDate();
char getStatus();

#endif
