#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream in;
    in.open("vehicles.txt");
    if(!in.is_open()){
        cerr<<"Error: File could not be opened!"<<endl;
        return 1;
    }

    string line;

    while(getline(in, line)){
        istringstream s(line);
        string Type, ID, Name, Year, ExtraData, Certification;

        getline(s, Type, ',');
        getline(s, ID, ',');
        getline(s, Name, ',');
        getline(s, Year, ',');
        getline(s, ExtraData, ',');
        getline(s, Certification, ',');

        if(Type=="AutonomousCar"){
            size_t pos= ExtraData.find(":");
            if(pos!= string::npos){
                string str = ExtraData.substr(pos+1);
                float SoftwareVersion = stof(str);
                cout<<"AutonomousCar ID: "<<ID<<"\nSoftware Version: "<<SoftwareVersion<<endl;
            }   
        }
        else if(Type=="ElectricVehicle"){
            size_t pos=ExtraData.find(":");
            if(pos!=string::npos){
                string str = ExtraData.substr(pos+1);
                int BatteryCapacity = stoi(str);
                cout<<"ElectricVehicle ID: "<<ID<<"\nBattery Capacity: "<<BatteryCapacity<<endl;
            }
        }
    }

    in.close();
    return 0;
}
