#include "StudentModule.h"

// LOW ATTENDANCE MODULE
// Function: showLowAttendance()

void showLowAttendance() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    bool found = false;

    cout << "\n--- Students Below 75% Attendance ---\n";

    for (int i = 0; i < studentCount; i++) {
        if (students[i].getPercentage() < 75.0) {
            students[i].showSummary();
            found = true;
        }
    }

    if (!found)
        cout << "No student has attendance below 75%.\n";
}
