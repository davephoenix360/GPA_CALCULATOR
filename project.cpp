/*
- Calculates student's CGPA given letter grades in each course.
- Provide insight into minimal qualifications to reach a CGPA.
- Can print GPA - grade letter chart
- Can print student's result page
- Can add new courses and their credits to the system
*/

#include<bits/stdc++.h>
using namespace std;



/*
Student Class:
- store student's current year
- store student's program
- store student's courses
- store student's full name
- store student's GPA
- store current semester
    Methods: 
    - Get courses
    - Calculate GPA
    - Print result sheet
    
System function
- Print menu
- Print courses
- Add a course and its credit
- Edit a course data
*/

class Student
{

private:
    bool state = false;
    int year;
    double cgpa;
    string name, program, semester;
    map<string, double> courses;
    map<string, string> courseGrades;

public:
    Student(string n, string p, string s, int y)
    {
        name = n;
        program = p;
        year = y;
        semester = s;
    };
    ~Student(){};
    void getCourses();
    void calculateGPA();
    void printResultSheet();

};

class Admin
{
    private:
        string username = "Admin";
        int passkey = 2023;
        bool loginstate = false;
    
    public:
        Admin()
        {
            loginstate = verifyAdminLogin();
        };
        ~Admin(){}
        bool verifyAdminLogin();
        bool editCourseList();

};


// FUNCTON DECLARATIONS //

/*Main function that controls the app.
Args: student{Student}
*/
void System(Student student);

/*This is the welcome function that creates the student object
and assigns all the information collected
Return: student(Student)
*/
Student welcome();

/*
Provides the main menu, handles t=choices and returns the choice(int) made.
Return: choice(int)
*/
int Menu();

/* Print all courses and store all courses in a map 
   Return: allCourses(map) 
*/
map<int, map<string, double>> printAllCourses();

/*
Converts a letter grade to the points in calculating the total GPA.
Return: points(int)
*/
double convertGradeToPoints(string lettergrade);

int main()
{
    Student student = welcome();
    System(student);
    return 0;
}

// FUNCTION DEFINITIONS

void System(Student student)
{
    int choice;
    choice = Menu();
    if(choice == 0)
    {
        cout << "Thank you";
    }
    if(choice == 1)
    {
        student.getCourses();
        student.calculateGPA();
        System(student);
    }
    if(choice == 2)
    {
        cout << "\n           You need the Admin login details            " << endl; 
        cout << "   to add or delete a course from the course list      " << endl << endl;
        Admin adminsession;
        adminsession.editCourseList();
        System(student);
    }
    if(choice == 3)
    {
        student.printResultSheet();
        System(student);
    }

}


Student welcome()
{
    string n, p, s, snew, pnew;
    int y;

    cout << "/-------------------------------------------------------/"<< endl;
    cout << "/-------------------------------------------------------/"<< endl;
    cout << "/---------------------Student Helper--------------------/"<< endl;    
    cout << "/-------------------------------------------------------/"<< endl;
    cout << "/-------------------------------------------------------/\n\n";
    cout << "          Welcome to the Student Helper Software         " << endl;
    cout << "  Here to help you with your CGPA goals and calculations " << endl << endl;
    cout << "                  What's your full name? - ";
    getline(cin, n);
    cout << "\n                What program are you doing? -  ";
    cin >> p;
    //transform(p.begin(), p.end(), pnew, ::toupper);
    cout << "\n                What year are you in?(number) - ";
    cin >> y;
    cout << "\n              Which semester are you in now? - ";
    cin >> s;
    //transform(s.begin(), s.end(), snew, ::toupper);
    cout << "\n";

    Student student(n, p, s, y);
    return student;
}


map<int, map<string, double>> printAllCourses() 
{
    cout << "           These are all the courses in our database     " << endl;
    cout << "    Please note that courses like ENGG 10 and ENGG 160   " << endl; 
    cout << "               don't count to your GPA"<< endl << endl;
    map<int, map<string, double>> allCourses;
    int i = 1;
    string courseinfo;
    string units;
    string name;
    ifstream coursesfile("courses.txt");

    while (coursesfile >> units >> name)
    {
        cout << "       (" << i << ") " << name << "          Units : " << units << endl;
        

        allCourses[i][name] = stod(units);
        i++;
    }
    
    coursesfile.close();
    return allCourses;
}


int Menu()
{
    int choice;
    cout << endl;
    cout << "                       ---  Menu  ---                    " << endl;
    cout << "                  1) Calculate your GPA                  " << endl;
    cout << "        2) Add or delete a course in the course list     " << endl;
    cout << "              3) Print your Sample Result Sheet          " << endl;
    cout << "                         0) Exit                         " << endl;

    cout << "\n                  Your Choice:          ";

    cin >> choice;
    cout << endl;
    while (choice > 3 || choice < 0)
    {
        cout << "Please select a valid option!   ";
        cin >> choice;
        cout << endl;
    }
    return choice;    
}

/*
Provides the user with the full list of archived courses
and prompts them to choose the courses they are taking in the semester
*/
void Student::getCourses()
{
    long long unsigned int choice;
    auto allCourses = printAllCourses();
    long long unsigned int noOfCourses = allCourses.size();
    cout << "\n   Choose all your courses using the iinstructions below " << endl;
    cout << "       Write the number corresponding to your course     " << endl;
    cout << "            press the enter key after every one          " << endl;
    cout << "      When finished, enter '0' and press the enter key   " << endl;
    cout << "                       Your choice:  ";
    
    cin >> choice;
    while (cin)
    {
        map<int, map<string, double>>::iterator myit = allCourses.begin();
        
        if(choice == 0)
        {
            break;
        }
        else if (choice > noOfCourses || choice < 1)
        {
            cout << "               Please enter a valid option: ";
        }
        
        else
        {
            while (choice>1)
            {
                ++myit;
                choice--;
            }
            
            map<string, double>::iterator tempit = myit->second.begin();
            courses[tempit->first] = tempit->second;
        }
        cin >> choice;

    }
    
    
}

/*
Calculates the GPA for a student(Class Student)
*/
void Student::calculateGPA()
{
    string lettergrade;
    double sumofunits = 0, sumofgradepoints = 0;
    
    cout << "Now I require your grades in each of your courses in the " << semester << " semester\n";
    
    for(auto i : courses)
    {
        cout << endl << "                       " << i.first << ": ";
        cin >> lettergrade;
        while (convertGradeToPoints(lettergrade) == -1)
        {
            cout << "Please enter a valid grade(A+,A,A-,B+,B,B-,C+,C,C-,D+,D,F) : ";
            cin >> lettergrade;
            cout << endl;
        }
        
        courseGrades[i.first] = lettergrade;
        sumofunits += i.second;
        sumofgradepoints += (i.second * convertGradeToPoints(lettergrade));
    }

    cgpa = sumofgradepoints/sumofunits;
    cgpa = round(cgpa * 100) / 100;
    cout << "              Your gpa is gpa = " << cgpa;

    state = true;
}


double convertGradeToPoints(string letter)

{
    if (letter == "A+" || letter == "A") { return 4.0; }
    else if (letter == "A-") {return 3.7;}
    else if (letter == "B+") {return 3.3;}
    else if (letter == "B") { return 3.0;}
    else if (letter == "B-") {return 2.7;}
    else if (letter == "C+") {return 2.3;}
    else if (letter == "C") {return 2.0;}
    else if (letter == "C-") {return 1.7;}
    else if (letter == "D+") {return 1.3;}
    else if (letter == "D") {return 1.0;}
    else if (letter == "F"){return 0.0;}
    else {return -1;}
    
}

/*
This function controls the logn feature for the admin
who has the ability to add or remove courses.
Return: bool (if successful or not)
*/
bool Admin::verifyAdminLogin()
{
    string name;
    int pass, trials = 5;

    cout << "\n             Username:  ";
    cin >> name;
    cout << "\n             Password:  ";
    cin >> pass;

    while ((username != name || passkey != pass) && trials > 0)
    {
        
        cout << "\n             Incorrect login details entered            " << endl;
        cout << "                   You have " << trials << " trial(s) left        " << endl;
        cout << "       Please try logging in with the correct details   " << endl;
        cout << "\n             Username:  ";
        cin >> name;
        cout << "\n             Password:  ";
        cin >> pass;
        trials--;
    }

    if (username != name || passkey != pass)
    {
        cout << "\n       Please contact developer for login details.      " << endl;
        cout << "           Going back to the main menu now              " << endl;
        return false;
    }

    else
    {
        cout << "                       Login successful!!                 " << endl << endl;
        return true;
    }
    
}

/*
Adds or deletes courses from the file courses.txt in the local directory
Returns: bool(true or false) if deletion or addition is successful
*/
bool Admin::editCourseList()
{
    int choice;
    double credits;
    string coursename;
    
    if (!loginstate)
    {
        return false;
    }
    
    cout << "                     Choose an option                    " << endl;
    cout << "                         0) Exit                         " << endl; 
    cout << "       1) Add a course             2) Remove a course    " << endl;
    cout << "                       Your Choice : "; 

    cin >> choice;
    
    if (choice == 0)
    {
        return true;
    }
    
    if (choice == 1)
    {
        cout << "       Enter the coursename(without any spaces) : ";
        cin >> coursename;
        cout << "           Enter the course's credits: ";
        cin >> credits;

        ofstream coursefile("courses.txt",ios::app);

        coursefile << "\n" << credits << " " << coursename;
        cout << "                  Operation successful.                " << endl;

        coursefile.close();
        return true;
    }

    else if (choice == 2)
    {
        string line;
        bool check = false;
        ifstream coursefile("courses.txt");
        ofstream tempfile("temp.txt");
        auto allCourses = printAllCourses();
        cout << "       Enter the number corresponding to the course    " << endl;
        cout << "           you want remove from the courselist         " << endl << endl;
        cout << "                       Your choice : ";
        cin >> choice;
        map<string, double>::iterator course = allCourses[choice].begin();

        while (coursefile >> credits >> coursename)
        {
            
            if(coursename == course->first && credits == course->second)
            {
                check = true;
            }
            else
            {
                tempfile << credits << " " << coursename << "\n";
            }
            
            
        }
        coursefile.close();
        tempfile.close();
        
        if (check && remove("courses.txt") == 0 && rename("temp.txt","courses.txt") == 0)
        {
            cout << "                  Operation successful.                " << endl;
            cout << "               Course deleted successfuly              " << endl;
            return check;
        }
        else
        {
            cout << "       Operation unsuccessful or course not found        " << endl;
            return check;
        }
    }
    return false;
}


void Student::printResultSheet()
{
    if(!state)
    {
        cout << "             You have to calculate your GPA             " << endl;
        cout << "             before printing a result sheet.            " << endl << endl;
    }
    else
    {
        int sumofunits = 0;
        int sumofgradepoints = 0;
        int gradepoint;
        cout.fill('-'); cout.width(70); cout << "\n";
        cout.fill('-'); cout.width(70); cout << "\n";
        cout.fill('-'); cout.width(42); cout << " RESULT  SHEET "; cout.fill('-'); cout.width(30); cout << "\n";
        cout.fill('-'); cout.width(70); cout << "\n";
        cout.fill('-'); cout.width(71); cout << "\n\n";
        cout << "Student Name:      " << this->name << "\t";
        cout << this->semester<< " TERM" << "    " << this->program << " " << this->year << " Year\n";
        cout << "Course \t Grade Remark \t Units \t Grade Points\n";

        for (auto i : this->courses)
        {
            sumofunits += i.second;
            gradepoint = (i.second * convertGradeToPoints(this->courseGrades[i.first]));
            sumofgradepoints += gradepoint;
            cout << i.first << " \t " << this->courseGrades[i.first] << " \t " << i.second << " \t\t" << gradepoint << "\n";
        }
        cout << "\n";
        cout.fill(' '); cout.width(25); cout << ""; cout << "TOTAL : " << sumofunits << "\t" << sumofgradepoints << "\n";
        cout.fill(' '); cout.width(25); cout << ""; cout << "Your GPA/Term avg. = " << this->cgpa << "\n";

        cout << "\n";
        cout.fill('-'); cout.width(70); cout << "\n";
        cout.fill('-'); cout.width(70); cout << "\n";
        
    }
    
}

