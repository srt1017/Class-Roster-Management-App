#pragma once
#include <iostream>
#include "student.h"
using namespace std;


class Roster {

public:
    
    Student* classRosterArray[5];
    int classRosterSize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);

    
    Roster();

    
    ~Roster();

    
    void add(string studentID, string studentFirstName, string studentLastName, string studentEmail, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram studentDegreeProgram, int index);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram studentDegreeProgram);



};

