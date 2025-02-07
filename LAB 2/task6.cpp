//
SHOBHA DUSEJA
24K-1006
//
#include <iostream>
using namespace std;

struct Student{
    string name;
    int rollNumber;
    int marks[3];
};

Student* createArr(int n){
    Student* Arr = new Student[n];
    cout << "Array of students is Created" << endl;
    return Arr;
}

void Details(Student* Arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Details for student " << i+1 << ": " << endl;
        cout << "NAME: ";
        cin.ignore();
        getline(cin, Arr[i].name);
        cout << "ROLL NO: ";
        cin >> Arr[i].rollNumber;
        for (int j = 0; j < 3; j++)
        {
            cout << "Marks for subject " << j+1 << ": ";
            cin >> Arr[i].marks[j];
        }
        
    }
    
}

double* calculateMarks(Student* Arr, int n){
    double* avg = new double[n];
    for (int i = 0; i < n; i++){
        avg[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            avg[i] += Arr[i].marks[j];
        }
        avg[i] /= 3;
    }
    return avg;
}

void displayAvg(Student* Arr,double* avg, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Average of " << Arr[i].name << ": " << avg[i] + 0.0 << endl;
    }
}


int main(){
    int size;
    cout << "kindly enter number of students: ";
    cin >> size;
    Student* Arr = createArr(size);
    Details(Arr, size);
    double* avg = calculateMarks(Arr, size);
    displayAvg(Arr, avg, size);
    return 0;
}
