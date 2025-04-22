#pragma once

#include "course.h"
#include <iostream>
using namespace std;

class Labcourse : public course {
    public:
    Labcourse(string courseCode, int credits) : course(courseCode, credits) {}

    void displayInfo() override {
        cout << "Lab Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

    double calculateGrade() override {
        return credits * 2.0;
    }

};
