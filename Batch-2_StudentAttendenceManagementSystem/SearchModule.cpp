#include "StudentModule.h"

// SEARCH MODULE
// Functions: searchStudent(), Student::showAttendance()

void searchStudent() {
    string rollNumber;

    cout << "Enter roll number to search: ";
    cin >> rollNumber;

    int index = findStudent(rollNumber);

    if (index == -1)
        cout << "Student not found.\n";
    else
        students[index].showAttendance();
}
