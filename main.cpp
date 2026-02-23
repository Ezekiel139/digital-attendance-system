#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Register Student
void registerStudent() {

    string name, index;

    cout << "Enter Student Name: ";
    cin >> name;

    cout << "Enter Index Number: ";
    cin >> index;

    ofstream file("students.txt", ios::app);
    file << name << " " << index << endl;
    file.close();

    cout << "Student Registered Successfully\n";
}

// View Students
void viewStudents() {

    ifstream file("students.txt");

    string name, index;

    cout << "\nRegistered Students\n";

    while(file >> name >> index) {
        cout << "Name: " << name << " Index: " << index << endl;
    }

    file.close();
}

// Mark Attendance
void markAttendance() {

    string index, status;

    cout << "Enter Student Index Number: ";
    cin >> index;

    cout << "Enter Attendance (Present/Absent/Late): ";
    cin >> status;

    ofstream file("attendance.txt", ios::app);
    file << index << " " << status << endl;
    file.close();

    cout << "Attendance Recorded\n";
}

// View Attendance Report
void viewReport() {

    ifstream file("attendance.txt");

    string index, status;

    int present = 0;
    int absent = 0;
    int late = 0;

    while(file >> index >> status) {

        cout << "Index: " << index << " Status: " << status << endl;

        if(status == "Present")
            present++;

        else if(status == "Absent")
            absent++;

        else if(status == "Late")
            late++;
    }

    cout << "\nSummary\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;

    file.close();
}

int main() {

    int choice;

    do {

        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. View Attendance Report\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                registerStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                markAttendance();
                break;

            case 4:
                viewReport();
                break;
        }

    } while(choice != 5);

    return 0;
}