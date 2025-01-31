//Shobha Duseja
//24K-1006


#include <iostream>
using namespace std;

// TASK 1 //

void calculateAQI(int AQIarr[][7]){
    int total = 0;
    float maxavg = 0;
    int worst;
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter data for  this city " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "DAY " << j+1 << ": ";
            cin >> AQIarr[i][j];
            total += AQIarr[i][j];
        }
        float avg = (float)total/7;
        total = 0;
        cout << endl << "Average of city " << i+1 << ": " << avg << endl;
        if (avg > maxavg){
            maxavg = avg;
            worst = i+1;
        }
    }
    cout << endl << "worst AQI City is: " << worst << endl;
}

// TASK 2 //

void displayCriticalPol(int AQIarr[][7]){
    for (int i = 0; i < 4; i++)
    {
        cout << endl << "CITY " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            if (AQIarr[i][j] > 150){
                cout << "DAY  " << j+1 << ": " << AQIarr[i][j] << endl;
            }
        }
    }
}


// TASK 3 //

void DataVisualization(int AQIarr[][7]){
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        cout << endl << "CITY " << i+1 << ": " << endl;
        for (int j = 0; j < 7; j++)
        {
            cout << "DAY " << j+1 << ": ";
            while (total < AQIarr[i][j]){
                cout << "*";
                total += 50;}
            cout << endl;
            total = 0;
        }
    }
}

// TASK 4 //

void MonthlyAQI(int AQIarr2[][4][7]){

    int total[4] = {0};
    float monthlyavg = 0;
    float avg[4] = {0};
    float diff[4] = {0};
    float max = 0;
    int largestDrop = 0;

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter Data for City " << i+1 << ": " << endl;
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 7; k++){
                cout << "DAY " << k+1 << ": ";
                cin >> AQIarr2[i][j][k];
                total[j] += AQIarr2[i][j][k];
            }
            avg[j] = (float)total[j]/7;
            total[j] = 0;
        }
        monthlyavg = (avg[0]+avg[1]+avg[2]+avg[3])/4;
        cout << "Monthly average for City " << i+1 << ": " <<
        monthlyavg << endl;
        diff[i] = avg[3] - avg[0];
        if (diff[i] > max){
            max = diff[i];
            largestDrop = i+1;
        }
    }
    cout << endl << "Most Improved City is = " << largestDrop << endl;
}


// TASK 5 // 

void generatingReport(int AQIarr2[][4][7]) {

    float weeklyavg[4][4] = {0};
    int maxAQI = 0, minAQI = 9999;
    int criticalpd[4][4][7] = {0};

    cout << endl << " Monthly Quality Report " << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl << "CITY" << i + 1 << " DATA:" << endl;
        for (int j = 0; j < 4; j++) {
            int total = 0;
            for (int k = 0; k < 7; k++) {
                int AQI = AQIarr2[i][j][k];
                total += AQI;

                if (AQI > 150) {
                    criticalpd[i][j][k] = 1; 
                }
                if (AQI > maxAQI) maxAQI = AQI;
                if (AQI < minAQI) minAQI = AQI;
            }
            weeklyavg[i][j] = (float)total / 7;
            cout << "  WEEK  " << j + 1 << " AVERAGE " << weeklyavg[i][j] << endl;
        }
    }

    cout << "\nCritical Pollution Days (AQI > 150):\n";
    for (int i = 0; i < 4; i++) {
        cout << "CITY " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 7; k++) {
                if (criticalpd[i][j][k] == 1) {
                    cout << "WEEK " << j + 1 << " DAY " << k + 1
                         << ": AQI " << AQIarr2[i][j][k] << endl;}
            }
        }
    }
    cout << "  highest AQI recorded: " << maxAQI << endl;
    cout << "  lowest AQI recorded: " << minAQI << endl;
}




int main(){
    int AQIarr[4][7];
    int AQIarr2[4][4][7];
    calculateAQI(AQIarr);
    displayCriticalPol(AQIarr);
    DataVisualization(AQIarr);
    MonthlyAQI(AQIarr2);
    generatingReport(AQIarr2);

    return 0;
}
