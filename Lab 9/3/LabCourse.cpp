#include "LabCourse.h"
#include <iostream>

LabCourse::LabCourse(string code, int credits, double reports, double exam)
    : Course(code, credits), labReports(reports), labExam(exam) {}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    cout << "Lab Reports: " << labReports << ", Lab Exam: " << labExam << endl;
}

double LabCourse::calculateGrade() {
    return (labReports * 0.5) + (labExam * 0.5);
}
