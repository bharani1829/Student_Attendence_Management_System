#include "StudentModule.h"

// SUMMARY MODULE
// Functions: showAllSummaries(), Student::showSummary()

void showAllSummaries() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    cout << "\n--- Attendance Summary ---\n";

    for (int i = 0; i < studentCount; i++)
        students[i].showSummary();
}
