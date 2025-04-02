#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactnum;
    string address;

public:
    Person(string n, int a, string c, string addr = "")
        : name(n), age(a), contactnum(c), address(addr) {}

    virtual void displayinfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "contact num: " << contactnum << endl;
        if (!address.empty()) {
            cout << "address: " << address << endl;
        }
    }

    virtual void updateInfo(string newInfo) = 0;  
};

class Patient : public Person {
private:
    string patientid;
    string medicalhistory;
    string doctorassigned;

public:
    Patient(string n, int a, string c, string id, string history, string doctor, string addr = "")
        : Person(n, a, c, addr), patientid(id), medicalhistory(history), doctorassigned(doctor) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "patient id: " << patientid << endl;
        cout << "medical history: " << medicalhistory << endl;
        cout << "doctor assigned: " << doctorassigned << endl;
    }

    void updateInfo(string newinfo) override {
        medicalhistory = newinfo;
        cout << "medical history updated: " << medicalhistory << endl;
    }
};


class Doctor : public Person {
private:
    string specialization;
    double consultationfee;
    Patient* patientslist[10];  
    int patientcount = 0;

public:
    Doctor(string n, int a, string c, string spec, double fee, string addr = "")
        : Person(n, a, c, addr), specialization(spec), consultationfee(fee) {}

    void addpatient(Patient* p) {
        if (patientcount < 10) {
            patientslist[patientcount++] = p;
        }
    }

    void displayinfo() override {
        Person::displayinfo();
        cout << "specialization: " << specialization << endl;
        cout << "consultation fee: $" << consultationfee << endl;
        cout << "patients assigned: " << endl;
    }

    void updateInfo(string newinfo) override {
        specialization = newinfo;
        cout << "specialization updated: " << specialization << endl;
    }
};

class Nurse : public Person {
private:
    string assignedward;
    string shifttimings;

public:
    Nurse(string n, int a, string c, string ward, string shift, string addr = "")
        : Person(n, a, c, addr), assignedward(ward), shifttimings(shift) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "assigned ward: " << assignedward << endl;
        cout << "shift timings: " << shifttimings << endl;
    }

    void updateInfo(string newinfo) override {
        assignedward = newinfo;
        cout << "assigned ward updated: " << assignedward << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string n, int a, string c, string dept, double sal, string addr = "")
        : Person(n, a, c, addr), department(dept), salary(sal) {}

    void displayinfo() override {
        Person::displayinfo();
        cout << "department: " << department << endl;
        cout << "salary: " << salary << endl;
    }

    void updateInfo(string newinfo) override {
        department = newinfo;
        cout << "department updated: " << department << endl;
    }
};

int main() {
   
    Doctor doc("Dr. Shobha", 20, "123-1234", "cardiology", 500.0);
   
    Patient patient("Hassan Raheem", 30, "567-5678", "P01", "Heart Disease", "Dr. Shobha");
   
    doc.addpatient(&patient);
   
    Nurse nurse("Minal", 20, "890-8900", "ICU", "9AM-5PM");
   
    Administrator admin("Rohit", 30, "432-4321", "HR", 5000.0);

 
    cout << "doctor info" << endl;
    doc.displayinfo();
    cout << endl;

    cout << "patient info" << endl;
    patient.displayinfo();
    cout << endl;

    cout << "nurse info" << endl;
    nurse.displayinfo();
    cout << endl;

    cout << "administrator info" << endl;
    admin.displayinfo();
    cout << endl;

    patient.updateInfo("high blood pressure");
    doc.updateInfo("neurology");
    nurse.updateInfo("emergency");
    admin.updateInfo("finance");

    return 0;
}