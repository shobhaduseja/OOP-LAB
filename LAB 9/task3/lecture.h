#pragma once

#include "course.h"
#include <iostream>
using namespace std;

class lecture : public course {
    public:
    lecture(string courseCode, int credits) : course(courseCode, credits) {}

    double calculateGrade() override {
        return credits * 2.0;
    }

    void displayInfo() override {
        cout << "Lecture: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
    }

};
