#include "StudentModule.h"

// Function declarations for the separate modules.
void addStudent();
void removeStudent();

void markAttendance();
void updateAttendance();

void searchStudent();

void showAttendanceCalculation(string rollNumber);

void showAllSummaries();

void showLowAttendance();

// MAIN / MENU MODULE

int main() {
    int choice;

    do {
        cout << "\n===============================================\n";
        cout << "     STUDENT ATTENDANCE MANAGEMENT SYSTEM\n";
        cout << "===============================================\n";

        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. Search and View Attendance\n";
        cout << "4. View Attendance Summary\n";
        cout << "5. View Low Attendance Students\n";
        cout << "6. Show Total Students\n";
        cout << "7. Update Attendance\n";
        cout << "8. Remove Student\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                markAttendance();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                showAllSummaries();
                break;

            case 5:
                showLowAttendance();
                break;

            case 6:
                cout << "Total students: "
                     << studentCount << endl;
                break;

            case 7:
                updateAttendance();
                break;

            case 8:
                removeStudent();
                break;

            case 0:
                cout << "Thank you.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
