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
    char status[MAX_DAYS];       // P = Present, A = Absent
    int attendanceCount;

public:
    static int totalStudents;

    // Default constructor
    Student() {
        rollNumber = "";
        name = "";
        attendanceCount = 0;
    }

    // Parameterized constructor
    Student(string roll, string studentName) {
        rollNumber = roll;
        name = studentName;
        attendanceCount = 0;
        totalStudents++;
    }

    // Destructor
    ~Student() {
    }

    // Get roll number
    string getRollNumber() const {
        return rollNumber;
    }

    // Get name
    string getName() const {
        return name;
    }

    // Check whether date already exists
    bool hasDate(string date) const {
        for (int i = 0; i < attendanceCount; i++) {
            if (dates[i] == date)
                return true;
        }
        return false;
    }

    // Mark attendance
    void markAttendance(string date, char attendanceStatus) {
        if (attendanceCount == MAX_DAYS) {
            cout << "Attendance limit reached for this student.\n";
            return;
        }

        if (hasDate(date)) {
            cout << "Attendance is already marked for this date.\n";
            return;
        }

        dates[attendanceCount] = date;
        status[attendanceCount] = attendanceStatus;
        attendanceCount++;

        cout << "Attendance marked successfully.\n";
    }

    // Update attendance
    bool updateAttendance(string date, char newStatus) {
        for (int i = 0; i < attendanceCount; i++) {
            if (dates[i] == date) {
                status[i] = newStatus;
                return true;
            }
        }

        return false;
    }

    // Calculate present days
    int getPresentDays() const {
        int present = 0;

        for (int i = 0; i < attendanceCount; i++) {
            if (status[i] == 'P')
                present++;
        }

        return present;
    }

    // Calculate absent days
    int getAbsentDays() const {
        return attendanceCount - getPresentDays();
    }

    // Calculate percentage
    double getPercentage() const {
        if (attendanceCount == 0)
            return 0.0;

        return (getPresentDays() * 100.0) / attendanceCount;
    }

    // Display attendance
    void showAttendance() const {
        cout << "\nRoll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;

        if (attendanceCount == 0) {
            cout << "No attendance records found.\n";
            return;
        }

        cout << left << setw(15) << "Date" << "Status\n";

        for (int i = 0; i < attendanceCount; i++) {
            cout << left << setw(15) << dates[i];

            if (status[i] == 'P')
                cout << "Present\n";
            else
                cout << "Absent\n";
        }
    }

    // Display summary
    void showSummary() const {
        cout << fixed << setprecision(2);

        cout << "Roll: " << rollNumber
             << ", Name: " << name
             << ", Present: " << getPresentDays()
             << ", Absent: " << getAbsentDays()
             << ", Percentage: " << getPercentage()
             << "%\n";
    }
};

// Definition of static variable
int Student::totalStudents = 0;


// Global student array
Student students[MAX_STUDENTS];
int studentCount = 0;


// Find student using roll number
int findStudent(string rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNumber() == rollNumber)
            return i;
    }

    return -1;
}


// Validate date
bool isValidDate(string date) {
    if (date.length() != 10)
        return false;

    if (date[2] != '-' || date[5] != '-')
        return false;

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5)
            continue;

        if (!isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}


// Get valid date
string getDate() {
    string date;

    while (true) {
        cin >> date;

        if (isValidDate(date))
            return date;

        cout << "Invalid date. Enter date in DD-MM-YYYY format: ";
    }
}


// Get valid attendance status
char getStatus() {
    char status;

    while (true) {
        cin >> status;

        status = toupper(static_cast<unsigned char>(status));

        if (status == 'P' || status == 'A')
            return status;

        cout << "Invalid status. Enter P or A: ";
    }
}


// Add student
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


// Mark attendance
void markAttendance() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    string date;

    cout << "Enter attendance date (DD-MM-YYYY): ";
    date = getDate();

    // Prevent duplicate attendance date
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


// Search student
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


// Show all summaries
void showAllSummaries() {
    if (studentCount == 0) {
        cout << "No students added yet.\n";
        return;
    }

    cout << "\n--- Attendance Summary ---\n";

    for (int i = 0; i < studentCount; i++)
        students[i].showSummary();
}


// Show students below 75%
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


// Update attendance
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


// Remove student
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

    // Shift students
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;

    cout << "Student removed successfully.\n";
}


// Main function
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