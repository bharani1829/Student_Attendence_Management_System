#include "StudentModule.h"

// ATTENDANCE CALCULATION MODULE
// Functions: Student::getPresentDays()
//            Student::getAbsentDays()
//            Student::getPercentage()

void showAttendanceCalculation(string rollNumber) {
    int index = findStudent(rollNumber);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Attendance Calculation ---\n";
    cout << "Student: " << students[index].getName() << endl;
    cout << "Present Days: " << students[index].getPresentDays() << endl;
    cout << "Absent Days: " << students[index].getAbsentDays() << endl;
    cout << "Attendance Percentage: "
         << students[index].getPercentage() << "%\n";
}
