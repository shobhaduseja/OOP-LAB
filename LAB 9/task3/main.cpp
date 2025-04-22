#include <iostream>
#include "course.h"
#include "Labcourse.h"
#include "lecture.h"
using namespace std;

int main() {
    Labcourse labCourse("OOP", 1);
    lecture lecture("Lecture", 3);
    labCourse.displayInfo();
    cout << "Grade: " << labCourse.calculateGrade() << endl;
    lecture.displayInfo();
    cout << "Grade: " << lecture.calculateGrade() << endl;
    return 0;
}
