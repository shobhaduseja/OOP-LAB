#include <iostream>
using namespace std;

class Employee{
    string name;
    string designation;
    
    public:
        Employee(string name, string designation) : name(name), designation(designation){}

        void display(){
            cout << "Employee Name: " << name << endl;
            cout << "Desgination: " << designation << endl;
        }

};
class Project{
    string title;
    string deadline;
    Employee* employees[10];
    int employeeCount = 0;

    public:
        Project(string title, string deadline) : title(title), deadline(deadline){}

        void addEmployee(Employee *e){
            employees[employeeCount++] = e;
        }

        void displayDetails(){
            cout << "Project Title: " << title << endl;
            cout << "Deadline: " << deadline << endl;
            for (int i = 0; i < employeeCount; i++)
            {
                employees[i]->display();
            }
        }
};

int main(){
    Employee e1("shobha", "PR head"), e2("aseelah", "Manager");

    Project project("Project", "7 march 2025");

    project.addEmployee(&e1);
    project.addEmployee(&e2);

    project.displayDetails();

    return 0;
}
