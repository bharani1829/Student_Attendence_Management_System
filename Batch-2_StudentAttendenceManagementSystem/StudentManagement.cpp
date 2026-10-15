#include "StudentModule.h"

// STUDENT MANAGEMENT MODULE
// Functions: addStudent(), findStudent(), removeStudent()

void addStudent() {
    if (studentCount == MAX_STUDENTS) {
        cout << "Student limit reached.\n";
        return;
    }

    string rollNumber;
    string name;

    cout << "Enter roll number: ";
    cin >> rollNumber;

    if (findStudent(rollNumber) != -1) {
        cout << "This roll number already exists.\n";
        return;
    }

    cout << "Enter student name: ";
    cin >> ws;
    getline(cin, name);

    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    students[studentCount] = Student(rollNumber, name);
    studentCount++;

    cout << "Student added successfully.\n";
}

void removeStudent() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    string rollNumber;

    cout << "Enter roll number to remove: ";
    cin >> rollNumber;

    int index = findStudent(rollNumber);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;

    cout << "Student removed successfully.\n";
}
