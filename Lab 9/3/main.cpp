#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main() {
    const int courseCount = 2;
    Course* courses[courseCount];

    courses[0] = new LectureCourse("CS101", 3, 78.0, 88.0, 86.0);
    courses[1] = new LabCourse("PHY201", 1, 90.0, 85.0);

    for (int i = 0; i < courseCount; ++i) {
        courses[i]->displayInfo();
        cout << "Final Grade: " << courses[i]->calculateGrade() << "\n\n";
    }

    for (int i = 0; i < courseCount; ++i) {
        delete courses[i];
    }

    return 0;
}
