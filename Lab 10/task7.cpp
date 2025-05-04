#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out("sensor_log.txt");
    if(!out){
        cerr<<"Error: can't open file!";
        return 1;
    }
    out<<"Sensor 1:25.5 C"<<endl;
    cout<<"Current writing position: "<<out.tellp()<<endl;

    out<<"Sensor:98.1 %RH"<<endl;
    cout<<"Current writing position: "<<out.tellp()<<endl;

    out.close();
    return 0;
}
