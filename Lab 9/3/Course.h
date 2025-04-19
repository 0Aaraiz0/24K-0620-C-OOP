#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int creditHours) : courseCode(code), credits(creditHours) {}
    virtual ~Course() {}

    virtual void displayInfo() = 0;
    virtual double calculateGrade() = 0;
};

#endif
