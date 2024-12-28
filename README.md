# 🎓 GPA Calculator

A command-line utility for students to manage academic records, calculate GPA, and generate result sheets.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Version](https://img.shields.io/badge/version-1.0-green.svg)
![C++](https://img.shields.io/badge/C++-11-00599C.svg)

## 📚 Overview

GPA Calculator helps students track their academic progress with features including:
- Automated GPA calculation based on course grades
- Administrative course management system
- Detailed result sheet generation
- Persistent data storage using file handling

## ✨ Key Features

### 📊 GPA Calculation
- Select courses from a curated list
- Input grades using standard letter format (A+, A, A-, etc.)
- Automatic CGPA computation

### 👩‍💼 Administrative Tools
- Secure admin login system
- Course list management
  - Add new courses
  - Remove existing courses
- Course database maintenance

### 📃 Result Sheet Generation
- Comprehensive academic reports including:
  - Student information
  - Course details with grades
  - Calculated CGPA
  - Semester summary

## 🔧 System Requirements

- **Compiler:** C++11 compatible (g++, MSVC)
- **IDE/Editor:** Any C++ compatible (VS Code, Visual Studio, Code::Blocks)
- **OS:** Cross-platform (Windows, Linux, macOS)

## 🚀 Getting Started

### Installation

```bash
# Clone the repository
git clone https://github.com/your-username/student-helper-software.git

# Navigate to project directory
cd student-helper-software

# Compile the program
g++ -o student_helper project.cpp

# Run the application
./student_helper
```

### 🔑 Admin Access
```
Username: Admin
Passkey: 2023
```

## 📖 Usage Guide

### Main Menu Options
1. **Calculate GPA**
   - Select courses from available list
   - Input grades
   - View calculated GPA

2. **Course Management** (Admin only)
   - Add/remove courses
   - Modify course details

3. **Result Sheet**
   - Generate detailed academic reports
   - View semester summary

### 📝 Course Data Format

Courses are stored in `courses.txt` with the following format:
```
3.0 Data Structures
4.0 Operating Systems
3.5 Calculus
```

## 📁 Project Structure

```
student-helper-software/
├── project.cpp     # Main program
├── courses.txt     # Course database
└── README.md       # Documentation
```

## 🛠️ Technical Details

### Core Components

#### Student Class
- `inputCourses()`: Course selection interface
- `calculateGPA()`: GPA computation engine
- `printResultSheet()`: Report generation

#### Admin Class
- `verifyLogin()`: Authentication system
- `modifyCourseList()`: Course management interface

## ❗ Troubleshooting

| Issue | Solution |
|-------|----------|
| File not found | Verify `courses.txt` exists in program directory |
| Invalid grade | Use standard grade format (A+, A, A-, B+, etc.) |
| Login failure | Confirm admin credentials |

## 📝 Example Usage

```plaintext
Welcome to GPA-Calculator
Full Name: John Doe
Program: Computer Science
Year: 2
Semester: Fall 2024

Available Courses:
(1) Data Structures - 3.0 credits
(2) Operating Systems - 4.0 credits
(3) Calculus - 3.5 credits

Your GPA: 3.70
```

## 📄 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## 🔮 Future Enhancements

- Course prerequisite management
- Automated transcript generation
- Grade trend analysis
- Academic progress tracking
- Semester planning tools

---

**Note:** For bug reports or feature requests, please open an issue in the repository.
