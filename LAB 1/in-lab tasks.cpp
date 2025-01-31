//Shobha Duseja
//24K-1006

#include <iostream>
using namespace std;

// TASK 1 //

void Names(string Event1[], string Event2[], int a, int b){
    cout << "enter your desired names for event 1: " << endl;
    for (int i = 0; i < a; i++)
    {
        cin >> Event1[i];
    }
    cout << "enter your desired names for event 2:" << endl;
    for (int i = 0; i < b; i++)
    {
        cin >> Event2[i];  
    }
}


void arrayDisplay(string Event1[], string Event2[], int a, int b){
    cout << endl << "EVENT 1 = " << endl;
    for (int i = 0; i < a; i++){
        cout << "entered name" << i+1 << ": " << Event1[i] << endl;
    }
    cout << "EVENT 2 : " << endl;
    for (int i = 0; i < b; i++){
        cout << "entered name " << i+1 << ": " << Event2[i] << endl;
    }
}

//  TASK 2 //

void checkAttendance(string Event1[], string Event2[], int a, int b){
    string name;
    cout << "please enter name to check =  ";
    cin >> name;
    for (int i = 0; i < a; i++){
        if (Event1[i] == name){
            cout <<"YES! " << name << " is registered in the event 1" << endl;
        }     
    }
    for (int i = 0; i < b; i++){
        if (Event2[i] == name){
            cout << "YES! " << name << " is registered in the event 2" << endl;
        }     
    }
}

// TASK 3 //

int totalDonations(int a, int b){
    int total = 0;
    for (int i = 0; i < a; i++){
        total += 10;}
    for (int i = 0; i < b; i++){
        total += 10;}
    return total;
}


// TASK 4 //

void displayReverse(string Event1[], string Event2[], int a, int b){
    cout << "Reserved order for: " << endl << "EVENT 1: " << endl;
    for (int i = a-1; i >= 0; i--)
    {
        cout << "entered name " << i+1 << ": " << Event1[i] << endl;
    }
    cout << "EVENT 2: " << endl;
    for (int i = b-1; i >= 0; i--)
    {
        cout << "entered name " << i+1 << ": " << Event2[i] << endl;
    }
}


// TASK 5 //

void BarChart(int a, int b){
    cout << endl << "BAR CHART for: " << endl << "EVENT 1: ";
    for (int i = 0; i < a; i++){
        cout << "*";
    }
    cout << endl;
    cout << "EVENT 2: ";
    for (int i = 0; i < b; i++)
    {
        cout << "*";
    }
}

int main(){
    string Event1[5], Event2[5];
    int a, b;
    cout << "enter no of participants for event 1: ";
    cin >> a;
    cout << "enter no of participants for event 2: ";
    cin >> b;
    Names(Event1, Event2, a, b);
    arrayDisplay(Event1, Event2, a,b);
    checkAttendance(Event1, Event2, a,b);
    int sum = totalDonations(a,b);
    cout << endl << " TOTAL DONATIONS ARE  = " << sum << endl << endl;
    displayReverse(Event1, Event2, a,b);
    BarChart(a,b);
    return 0;
}
