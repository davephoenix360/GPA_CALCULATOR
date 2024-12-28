// Filename: project.cpp

/*
Student Helper Software:
- Calculates student's CGPA given letter grades in each course.
- Provides insights into qualifications to reach a target CGPA.
- Manages courses and allows adding/removing them.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

// Forward declarations
class Student;
class Admin;

// Function declarations
void systemMenu(Student &student);
Student welcome();
int displayMenu();
unordered_map<int, pair<string, double>> loadCourses();
double gradeToPoints(const string &letterGrade);

// --- Student Class ---
class Student {
private:
    string name, program, semester;
    int year;
    double cgpa;
    unordered_map<string, double> courses;
    unordered_map<string, string> courseGrades;

public:
    Student(const string &name, const string &program, const string &semester, int year)
        : name(name), program(program), semester(semester), year(year), cgpa(0.0) {}

    void inputCourses();
    void calculateGPA();
    void printResultSheet() const;

    // Getters for potential future use
    string getName() const { return name; }
    string getProgram() const { return program; }
};

// --- Admin Class ---
class Admin {
private:
    const string username = "Admin";
    const int passkey = 2023;
    bool loginState = false;

    bool verifyLogin();
    bool modifyCourseList();

public:
    Admin() { loginState = verifyLogin(); }

    void manageCourses() {
        if (loginState) {
            modifyCourseList();
        }
    }
};

// --- Main Function ---
int main() {
    Student student = welcome();
    systemMenu(student);
    return 0;
}

// --- Function Definitions ---
Student welcome() {
    string name, program, semester;
    int year;

    cout << "Welcome to Student Helper Software\n";
    cout << "Please provide the following details:\n";
    cout << "Full Name: ";
    getline(cin, name);
    cout << "Program: ";
    getline(cin, program);
    cout << "Year (numeric): ";
    cin >> year;
    cin.ignore(); // Clear newline character from input buffer
    cout << "Semester: ";
    getline(cin, semester);

    return Student(name, program, semester, year);
}

void systemMenu(Student &student) {
    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
        case 1:
            student.inputCourses();
            student.calculateGPA();
            break;
        case 2:
            {
                Admin admin;
                admin.manageCourses();
            }
            break;
        case 3:
            student.printResultSheet();
            break;
        case 0:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int displayMenu() {
    cout << "\n--- Main Menu ---\n"
         << "1) Calculate your GPA\n"
         << "2) Manage courses (Admin only)\n"
         << "3) Print your result sheet\n"
         << "0) Exit\n"
         << "Your choice: ";

    int choice;
    cin >> choice;
    return choice;
}

unordered_map<int, pair<string, double>> loadCourses() {
    unordered_map<int, pair<string, double>> courses;
    ifstream file("courses.txt");

    if (!file) {
        cerr << "Error: Unable to open courses file.\n";
        return courses;
    }

    string courseName;
    double credits;
    int index = 1;

    while (file >> credits >> ws && getline(file, courseName)) {
        courses[index++] = {courseName, credits};
    }

    file.close();
    return courses;
}

void Student::inputCourses() {
    auto allCourses = loadCourses();
    if (allCourses.empty()) {
        cout << "No courses available.\n";
        return;
    }

    cout << "\nAvailable Courses:\n";
    for (const auto &entry : allCourses) {
        cout << "(" << entry.first << ") " << entry.second.first << " - " << entry.second.second << " credits\n";
    }

    cout << "\nEnter the numbers corresponding to your courses (0 to finish):\n";
    int choice;
    while (cin >> choice && choice != 0) {
        if (allCourses.count(choice)) {
            const auto &course = allCourses[choice];
            courses[course.first] = course.second;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void Student::calculateGPA() {
    if (courses.empty()) {
        cout << "No courses selected.\n";
        return;
    }

    double totalCredits = 0, totalGradePoints = 0;

    for (const auto &course : courses) {
        cout << "Enter grade for " << course.first << ": ";
        string grade;
        cin >> grade;

        double gradePoints = gradeToPoints(grade);
        while (gradePoints == -1) {
            cout << "Invalid grade. Please enter a valid grade (A+, A, A-, etc.): ";
            cin >> grade;
            gradePoints = gradeToPoints(grade);
        }

        courseGrades[course.first] = grade;
        totalCredits += course.second;
        totalGradePoints += course.second * gradePoints;
    }

    cgpa = round((totalGradePoints / totalCredits) * 100) / 100;
    cout << "Your GPA is: " << fixed << setprecision(2) << cgpa << "\n";
}

void Student::printResultSheet() const {
    cout << "\n--- Result Sheet ---\n"
         << "Name: " << name << "\n"
         << "Program: " << program << "\n"
         << "Semester: " << semester << "\n"
         << "Year: " << year << "\n"
         << "Courses and Grades:\n";

    for (const auto &entry : courses) {
        cout << entry.first << " (" << entry.second << " credits): " << courseGrades.at(entry.first) << "\n";
    }

    cout << "CGPA: " << fixed << setprecision(2) << cgpa << "\n";
}

double gradeToPoints(const string &letterGrade) {
    static const unordered_map<string, double> gradeMap = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7}, {"B+", 3.3},
        {"B", 3.0}, {"B-", 2.7}, {"C+", 2.3}, {"C", 2.0},
        {"C-", 1.7}, {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };

    auto it = gradeMap.find(letterGrade);
    return it != gradeMap.end() ? it->second : -1.0;
}

bool Admin::verifyLogin() {
    string inputUsername;
    int inputPasskey;
    cout << "Admin Login:\nUsername: ";
    cin >> inputUsername;
    cout << "Passkey: ";
    cin >> inputPasskey;

    if (inputUsername == username && inputPasskey == passkey) {
        cout << "Login successful.\n";
        return true;
    }

    cout << "Login failed. Returning to main menu.\n";
    return false;
}

bool Admin::modifyCourseList() {
    cout << "\n--- Modify Course List ---\n"
         << "1) Add a course\n"
         << "2) Remove a course\n"
         << "0) Exit\n"
         << "Your choice: ";

    int choice;
    cin >> choice;

    if (choice == 0) return true;

    string courseName;
    double credits;

    if (choice == 1) {
        cout << "Enter course name: ";
        cin.ignore();
        getline(cin, courseName);
        cout << "Enter course credits: ";
        cin >> credits;

        ofstream file("courses.txt", ios::app);
        if (file) {
            file << credits << " " << courseName << "\n";
            cout << "Course added successfully.\n";
        } else {
            cerr << "Error adding course.\n";
        }
        file.close();
    } else if (choice == 2) {
        // Implementation for course removal (not provided in original code)
        cout << "Course removal feature not implemented.\n";
    }

    return true;
}
