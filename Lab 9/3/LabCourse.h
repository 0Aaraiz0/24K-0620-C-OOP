#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course {
private:
    double labReports;
    double labExam;

public:
    LabCourse(string code, int credits, double reports, double exam);
    void displayInfo() override;
    double calculateGrade() override;
};

#endif
