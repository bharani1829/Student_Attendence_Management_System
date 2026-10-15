#include "StudentModule.h"

Student students[MAX_STUDENTS];
int studentCount = 0;

Student::Student() {
    rollNumber = "";
    name = "";
    attendanceCount = 0;
}

Student::Student(string roll, string studentName) {
    rollNumber = roll;
    name = studentName;
    attendanceCount = 0;
}

Student::~Student() {
}

string Student::getRollNumber() const {
    return rollNumber;
}

string Student::getName() const {
    return name;
}

bool Student::hasDate(string date) const {
    for (int i = 0; i < attendanceCount; i++) {
        if (dates[i] == date)
            return true;
    }
    return false;
}

void Student::markAttendance(string date, char attendanceStatus) {
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

bool Student::updateAttendance(string date, char newStatus) {
    for (int i = 0; i < attendanceCount; i++) {
        if (dates[i] == date) {
            status[i] = newStatus;
            return true;
        }
    }
    return false;
}

int Student::getPresentDays() const {
    int present = 0;

    for (int i = 0; i < attendanceCount; i++) {
        if (status[i] == 'P')
            present++;
    }

    return present;
}

int Student::getAbsentDays() const {
    return attendanceCount - getPresentDays();
}

double Student::getPercentage() const {
    if (attendanceCount == 0)
        return 0.0;

    return (getPresentDays() * 100.0) / attendanceCount;
}

void Student::showAttendance() const {
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

void Student::showSummary() const {
    cout << fixed << setprecision(2);

    cout << "Roll: " << rollNumber
         << ", Name: " << name
         << ", Present: " << getPresentDays()
         << ", Absent: " << getAbsentDays()
         << ", Percentage: " << getPercentage()
         << "%\n";
}

int findStudent(string rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].getRollNumber() == rollNumber)
            return i;
    }

    return -1;
}

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

string getDate() {
    string date;

    while (true) {
        cin >> date;

        if (isValidDate(date))
            return date;

        cout << "Invalid date. Enter date in DD-MM-YYYY format: ";
    }
}

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
