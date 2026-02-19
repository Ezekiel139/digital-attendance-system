#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Requirement 5.1: Student Management Class
class Student {
private:
    string indexNumber;
    string name;

public:
    Student(string id, string n) : indexNumber(id), name(n) {}

    // Getters for searching and displaying (Req 5.1.3)
    string getIndex() const { return indexNumber; }
    string getName() const { return name; }

    void display() const {
        cout << "Index: " << indexNumber << " | Name: " << name << endl;
    }
};

// Function prototypes
void registerStudent(vector<Student> &list);
void viewStudents(const vector<Student> &list);

int main() {
    vector<Student> studentList;
    int choice;

    // Requirement 3: Menu-driven interface
    do {
        cout << "\n--- EEE227 ATTENDANCE SYSTEM ---" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. View All Registered Students" << endl;
        cout << "3. Exit" << endl;
        cout << "Select Option: ";
        cin >> choice;

        if (choice == 1) {
            registerStudent(studentList);
        } else if (choice == 2) {
            viewStudents(studentList);
        }
    } while (choice != 3);

    return 0;
}

// Req 5.1.1: Register students
void registerStudent(vector<Student> &list) {
    string id, name;
    cout << "Enter Student Index: ";
    cin >> id;
    cin.ignore(); // Clears the buffer for name input
    cout << "Enter Full Name: ";
    getline(cin, name);
    
    list.push_back(Student(id, name));
    cout << "Student successfully registered!" << endl;
}

// Req 5.1.2: View all students
void viewStudents(const vector<Student> &list) {
    if (list.empty()) {
        cout << "No students registered." << endl;
        return;
    }
    cout << "\n--- Student Directory ---" << endl;
    for (const auto &s : list) {
        s.display();
    }
}