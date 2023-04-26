#include <iostream>
#include <sstream>
#include "Roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main()
{
    cout << "Class: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming language used: C++" << endl;
    cout << "Name: Omar Farooq. Student ID: 010292591" << endl;

    Roster classRoster;

    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < classRoster.classRosterSize; i++) {

        string studentID = classRoster.classRosterArray[i]->GetStudentID();

        classRoster.printAverageDaysInCourse(studentID);
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
