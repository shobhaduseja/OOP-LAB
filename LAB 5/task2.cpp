#include <iostream>
using namespace std;

class Student {
    int id;
    string name;
    int* examScores;
    int size;

public:
    Student(int id, string n, int examScoreArr[], int s) : id(id), name(n), size(s) {
        examScores = new int[size];
        for (int i = 0; i < size; i++) {
            examScores[i] = examScoreArr[i];
        }
    }

    Student(const Student &obj) {
        id = obj.id;
        name = obj.name;
        size = obj.size;
        examScores = new int[size];
        for (int i = 0; i < size; i++) {
            examScores[i] = obj.examScores[i];
        }
    }

    ~Student() {
        delete[] examScores; 
    }

    void displayDetails() {
        cout << "ID: " << &ID << endl;
        cout << "Name: " << &name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < size; i++) {
            cout << &examScores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter number of exams: ";
    cin >> size;

    int* score = new int[size]; 
    cout << "Enter your exam scores: ";
    for (int i = 0; i < size; i++) {
        cin >> score[i];
    }

    Student std1(33333, "shobha", score, size);
    Student std2(std1); 

    std1.displayDetails();
    std2.displayDetails();

    delete[] score; 
    return 0;
}
