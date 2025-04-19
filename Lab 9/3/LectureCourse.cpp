#include "LectureCourse.h"
#include <iostream>

LectureCourse::LectureCourse(string code, int credits, double mid, double final_, double assign)
    : Course(code, credits), midterm(mid), finalExam(final_), assignments(assign) {}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    cout << "Midterm: " << midterm << ", Final Exam: " << finalExam << endl;
}

double LectureCourse::calculateGrade() {
    return (midterm * 0.3) + (finalExam * 0.5) + (assignments * 0.2);
}
