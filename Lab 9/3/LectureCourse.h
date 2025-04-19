#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course {
private:
    double midterm;
    double finalExam;
    double assignments;

public:
    LectureCourse(string code, int credits, double mid, double final_, double assign);
    void displayInfo() override;
    double calculateGrade() override;
};

#endif
