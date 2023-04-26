#include "Roster.h"
#include <sstream>
#include <iostream>
#include "degree.h"
#include "degree.h"
using namespace std;

Roster::Roster() {

    Student* classRosterArray[5];

    string StudentID;
    string studentFirstName;
    string studentLastName;
    string studentEmail;
    string ageString;
    int studentAge;
    string daysInCourse1String;
    string daysInCourse2String;
    string daysInCourse3String;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    string degreeProgramString;
    DegreeProgram studentDegreeProgram;

    const string studentDataString[] =
    {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Omar,Farooq,ofarooq2@my.wgu.edu,22j,24,14,12,SOFTWARE"
    };

    int number = sizeof(studentDataString) / sizeof(studentDataString[0]);



    for (int i = 0; i < number; i++) {

        string name;

        string myString = studentDataString[i];
        stringstream myStream(myString);

        getline(myStream, StudentID, ',');
        getline(myStream, studentFirstName, ',');
        getline(myStream, studentLastName, ',');
        getline(myStream, studentEmail, ',');
        getline(myStream, ageString, ',');
        studentAge = stoi(ageString);
        getline(myStream, daysInCourse1String, ',');
        daysInCourse1 = stoi(daysInCourse1String);
        getline(myStream, daysInCourse2String, ',');
        daysInCourse2 = stoi(daysInCourse2String);
        getline(myStream, daysInCourse3String, ',');
        daysInCourse3 = stoi(daysInCourse3String);
        getline(myStream, degreeProgramString, ',');

        if (degreeProgramString == "SECURITY") {
            studentDegreeProgram = SECURITY;
        }
        else if (degreeProgramString == "NETWORK") {
            studentDegreeProgram = NETWORK;
        }
        else if (degreeProgramString == "SOFTWARE") {
            studentDegreeProgram = SOFTWARE;
        }

        add(StudentID, studentFirstName, studentLastName, studentEmail, studentAge, daysInCourse1, daysInCourse2, daysInCourse3, studentDegreeProgram, i);

    }
    cout << endl;

}



void Roster::add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int ageInput, int daysInCourse1Input, int daysInCourse2Input, int daysInCourse3Input, DegreeProgram degreeProgramInput, int index) {

    int daysSplit[] = { daysInCourse1Input, daysInCourse2Input, daysInCourse3Input };

    classRosterArray[index] = new Student(studentID, studentFirstName, studentLastName, studentEmail, ageInput, daysSplit, degreeProgramInput);


};
void Roster::remove(string studentID) {

    cout << "This student ID (" << studentID << ") will now be removed from the roster." << endl;
    for (int i = 0; i < classRosterSize; i++) {

        if (classRosterArray[i] != 0) {

            string studID = classRosterArray[i]->GetStudentID();

            if (studentID == studID) {
                classRosterArray[i] = 0;
                cout << "This student has been successfully removed." << endl;
            }


        }

        else {
            cout << "ERROR: A student does not exist at this roster index. Please try again with a valid student ID." << endl;
        }

    }

    cout << endl;
};

void Roster::printAll() {
    cout << "Displaying all students information:" << endl;

    for (int i = 0; i < classRosterSize; i++) {
        classRosterArray[i]->print();
    }

    cout << endl;

};


void Roster::printAverageDaysInCourse(string studentID) {

    for (int i = 0; i < classRosterSize; i++) {
        string studID = classRosterArray[i]->GetStudentID();

        if (studentID == studID) {

            int courseLength1 = classRosterArray[i]->GetDaysInCourse()[0];
            int courseLength2 = classRosterArray[i]->GetDaysInCourse()[1];
            int courseLength3 = classRosterArray[i]->GetDaysInCourse()[2];

            cout << classRosterArray[i]->GetFirstName() << "'s average number of days to complete a course is: " << (courseLength1 + courseLength2 + courseLength3) / 3;

        }

    }
    cout << endl;

};

void Roster::printInvalidEmails() {

    cout << "Here is the list of emails that are invalid:" << endl;
    for (int i = 0; i < classRosterSize; i++) {
        string studentEmail = classRosterArray[i]->GetEmail();

        if (studentEmail.find(' ') != string::npos) {
            cout << "This email: " << studentEmail << " is invalid: Spaces are illegal. " << endl;
        }

        if (studentEmail.find('.') != string::npos) {

        }
        else {
            cout << "This email: " << studentEmail << " is invalid: '.' is required. " << endl;
        };

        if (studentEmail.find('@') != string::npos) {

        }
        else {
            cout << "This email: " << studentEmail << " is invalid: '@' is required. " << endl;
        }

    }

    cout << endl;

};


void Roster::printByDegreeProgram(DegreeProgram studentDegreeProgram) {

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

    cout << endl;
    cout << "Here is the list of students enrolled in the program: " << degreeProgramString << endl;

    for (int i = 0; i < classRosterSize; i++) {

        DegreeProgram degreeProg = classRosterArray[i]->GetDegreeProgram();

        if (classRosterArray[i] != 0) {

            if (studentDegreeProgram == degreeProg) {
                classRosterArray[i]->print();
            }

        }

    }

    cout << endl;
};



Roster::~Roster() {
    cout << "Roster destructor has been called.";
}
