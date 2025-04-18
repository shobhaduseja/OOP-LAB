#include <iostream>
#include <string>

using namespace std;

class Patient {
protected:
    string name;
    string ID;

public:
    Patient(string n, string i) : name(n), ID(i) {}

    virtual void displayTreatment() = 0;
    virtual void calculateCost() = 0;
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "inpatient treatment plan for " << name << " ID: " << ID << endl;
        cout << "Hospitalization and surgery if necessary." << endl;
    }

    void calculateCost() {
        cout << "Cost for patient for " << name <<" is" << "$5000" << endl;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() {
        cout << "Outpatient treatment plan for " << name << endl;
        cout << "Consultation, diagnostics, follow-up visits as required." << endl;
    }

    void calculateCost() {
        cout << "Cost for outpatient care for " << name << "  and ID: " << ID << " is $200" << endl;
    }
};

int main() {
    Patient* p1 = new InPatient("shobha", "2399");
    Patient* p2 = new OutPatient("aseelah", "h7883");

    p1->displayTreatment();
    p1->calculateCost();
    p2->displayTreatment();
    p2->calculateCost();

    delete p1;
    delete p2;

    return 0;
}
