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

        int year= stoi(Year);
        cout<<"ID:"<<ID<<endl;
        cout<<"Year(int): "<<year<<endl;
    }

    in.close();
    return 0;
}
