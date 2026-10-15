#include "StudentModule.h"

// ATTENDANCE MANAGEMENT MODULE
// Functions: markAttendance(), updateAttendance()

void markAttendance() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    string date;

    cout << "Enter attendance date (DD-MM-YYYY): ";
    date = getDate();

    // Prevent duplicate attendance date for the whole class.
    for (int i = 0; i < studentCount; i++) {
        if (students[i].hasDate(date)) {
            cout << "Attendance for " << date
                 << " is already marked.\n";
            return;
        }
    }

    cout << "\n--- Marking Attendance for "
         << date << " ---\n";

    for (int i = 0; i < studentCount; i++) {
        cout << students[i].getRollNumber()
             << " - "
             << students[i].getName()
             << " (P = Present, A = Absent): ";

        char attendanceStatus = getStatus();

        students[i].markAttendance(date, attendanceStatus);
    }
}

void updateAttendance() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    string rollNumber;

    cout << "Enter roll number: ";
    cin >> rollNumber;

    int index = findStudent(rollNumber);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    string date;

    cout << "Enter date to update (DD-MM-YYYY): ";
    date = getDate();

    if (!students[index].hasDate(date)) {
        cout << "No attendance record found for this date.\n";
        return;
    }

    cout << "Enter new status (P = Present, A = Absent): ";

    char newStatus = getStatus();

    students[index].updateAttendance(date, newStatus);

    cout << "Attendance updated successfully.\n";
}
