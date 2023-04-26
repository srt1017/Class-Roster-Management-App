#include "student.h"
#include "degree.h"
#include <iostream> 

using namespace std;


Student::Student(string studentIDvar, string firstNameVar, string lastNameVar, string studentEmail, int studentAge, int* daysInCourses, DegreeProgram degreeProgramEntry) {

    StudentID = studentIDvar;
    FirstName = firstNameVar;
    LastName = lastNameVar;
    Email = studentEmail;
    Age = studentAge;
    DaysInCourse[0] = daysInCourses[0];
    DaysInCourse[1] = daysInCourses[1];
    DaysInCourse[2] = daysInCourses[2];
    studentDegreeProgram = degreeProgramEntry;

}

string Student::GetStudentID() {
    return StudentID;
}

string Student::GetFirstName() {
    return FirstName;
}

string Student::GetLastName() {
    return LastName;
}

string Student::GetEmail() {
    return Email;
}

int Student::GetAge() {
    return Age;
}

int* Student::GetDaysInCourse() {
    return DaysInCourse;
}

DegreeProgram Student::GetDegreeProgram() {
    return studentDegreeProgram;
}

void Student::SetStudentID(string studentID) {
    StudentID = studentID;
}

void Student::SetFirstName(string firstNameVar) {
    FirstName = firstNameVar;
}

void Student::SetLastName(string lastNameVar) {
    LastName = lastNameVar;
}

void Student::SetEmail(string emailEntry) {
    Email = emailEntry;
}

void Student::SetAge(int ageEntry) {
    Age = ageEntry;
}

void Student::SetDaysInCourse(int DayEntry, int CourseNumber) {
    DaysInCourse[CourseNumber - 1] = DayEntry;
}

void Student::SetDegreeProgram(DegreeProgram degreeEntry) {
    studentDegreeProgram = degreeEntry;
}


void Student::print() {

    DegreeProgram studentDegreeProgram = GetDegreeProgram();
    string degreeProgramString;

    if (studentDegreeProgram == SECURITY) {
        degreeProgramString = "SECURITY";
    }
    else if (studentDegreeProgram == NETWORK) {
        degreeProgramString = "NETWORK";
    }
    else if (studentDegreeProgram == SOFTWARE) {
        degreeProgramString = "SOFTWARE";
    }

    cout << GetStudentID() << " First Name: " << GetFirstName() << "    Last Name: " << GetLastName() << "  Age: " << GetAge() << "   daysInCourse: {" << DaysInCourse[0] << "," << DaysInCourse[1] << "," << DaysInCourse[2] << "}" << "    Degree Program: " << degreeProgramString << endl;

};