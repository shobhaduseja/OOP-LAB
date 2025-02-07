//
SHOBHA DUSEJA
24K-1006
//
  
#include <iostream>
#include <string>
using namespace std;

struct employee
{
    string name;
    float hoursWorked;
    float hourlyRate;
};

int main()
{
    int n;
    cout << "Enter the number of employees you: ";
    cin >> n;
    cin.ignore();
    employee *employees = new employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Employee " << i + 1 << " name: ";
        getline(cin, employees[i].name);
        cout << "Enter the Employee " << i + 1 << " Hours worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Enter the Employee " << i + 1 << " Hourly rate: ";
        cin >> employees[i].hourlyRate;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Salary of employee " << employees[i].name << ": " << employees[i].hourlyRate * employees[i].hoursWorked << endl;
    }
    delete[] employees;
    return 0;
}
