GPA-Calculator

Description

The GPA-Calculator is a command-line program designed to assist students in managing their academic data. It provides several key functionalities:

GPA Calculation: Students can input their course grades and calculate their CGPA.

Course Management: Admins can add or remove courses from a list of available courses.

Result Sheet Generation: The software generates a printable result sheet that includes courses, grades, and the CGPA.


The program uses basic file handling to load courses and store them persistently, and it offers a user-friendly interface to manage student academic details.


---

Features

1. Calculate GPA

Students can select from a list of available courses and input their grades.

GPA is calculated based on the student's selected courses and grades.

Supports common letter grades (e.g., A+, A, A-, B+, B, etc.).



2. Admin Functionality

Admin users can log in to manage the list of available courses.

Admins can add new courses to the list.

Admins can remove courses from the list (if implemented).



3. Result Sheet

Students can generate and print a detailed result sheet that includes:

Student details (name, program, semester, etc.).

List of courses with grades.

CGPA calculated based on the entered grades.






---

Requirements

To run the GPA-Calculator, ensure you have the following:

C++ compiler: Compatible with C++11 or later (e.g., g++, MSVC).

Text Editor/IDE: Any C++ compatible IDE or text editor (e.g., Visual Studio, Code::Blocks, VS Code).

Operating System: Any OS with a C++ compiler (Windows, Linux, macOS).



---

How to Run the Program

Step 1: Clone the Repository

Clone the repository to your local machine.

git clone https://github.com/your-username/student-helper-software.git
cd student-helper-software

Step 2: Compile the Program

Ensure you have a C++ compiler installed. If using g++, run the following command to compile the program.

g++ -o student_helper project.cpp

Step 3: Run the Program

After compiling, run the program using:

./student_helper

The program will display a menu and guide you through different options like calculating GPA, managing courses (if you're an admin), and generating a result sheet.


---

Usage

Main Menu

Upon launching the program, you will be presented with the main menu with the following options:

1. Calculate your GPA: Allows students to input grades for selected courses and calculates the GPA.


2. Manage courses (Admin only): If you're an admin, you can log in to modify the course list (add/remove courses).


3. Print your result sheet: Generates and prints a result sheet with your courses and GPA.


4. Exit: Exits the program.



Admin Login

To access the course management features, admins will be prompted for a username and passkey:

Username: Admin

Passkey: 2023



---

Course File Format

The program reads course data from the courses.txt file. Each line in the file should contain the course credit and course name, separated by a space. For example:

3.0 Data Structures
4.0 Operating Systems
3.5 Calculus

Adding Courses

Admins can add new courses via the admin menu. The course information will be appended to the courses.txt file.


---

Functionality in Detail

1. Student Class

inputCourses(): Allows students to input the courses they are taking, based on the available course list.

calculateGPA(): Calculates the student's GPA based on their selected courses and entered grades.

printResultSheet(): Generates and prints a result sheet with student details, selected courses, and calculated CGPA.


2. Admin Class

verifyLogin(): Admins log in using the preset username (Admin) and passkey (2023).

modifyCourseList(): Allows admins to add or remove courses from the available list.



---

Example

Sample Output

Welcome to GPA-Calculator
Please provide the following details:
Full Name: John Doe
Program: Computer Science
Year (numeric): 2
Semester: Fall 2024

--- Main Menu ---
1) Calculate your GPA
2) Manage courses (Admin only)
3) Print your result sheet
0) Exit
Your choice: 1

Available Courses:
(1) Data Structures - 3.0 credits
(2) Operating Systems - 4.0 credits
(3) Calculus - 3.5 credits

Enter the numbers corresponding to your courses (0 to finish):
1
Enter grade for Data Structures: A
2
Enter grade for Operating Systems: A-
3
Enter grade for Calculus: B+

Your GPA is: 3.70


---

File Structure

student-helper-software/
│
├── project.cpp           # Main C++ program file
├── courses.txt           # Text file with course data (credit and course name)
└── README.md             # Project description and documentation


---

Troubleshooting

1. File not found: If the program is unable to open courses.txt, ensure that the file exists in the same directory as the project.cpp file.


2. Invalid grade: If an invalid grade is entered (e.g., "E"), the program will prompt the user to enter a valid grade (A+, A, A-, B+, etc.).


3. Admin login failure: If login fails, ensure you're using the correct admin username (Admin) and passkey (2023).




---

License

This project is licensed under the MIT License - see the LICENSE file for details.


---

Conclusion

This GPA-Calculator provides a user-friendly way for students to manage their grades and calculate GPA while offering an administrative interface to modify the course list. The software can be expanded in the future to include additional features like course prerequisites, transcript generation, and more.
