#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out("config.txt");
    if(!out){
        cerr<<"Error: can't open file!";
        return 1;
    }
    out<<"AAAAA"<<endl;
    out<<"BBBBB"<<endl;
    out<<"CCCCC"<<endl;
    out.close();

    fstream f("config.txt", ios::in |ios::out);
    if(!f){
        cerr<<"Error: can't open file!";
        return 1;
    }
    f.seekp(7,ios::beg);
    f.write("XXXXX",5);
    f.close();

    ifstream inFile("config.txt");

    if(!inFile){
        cerr << "error,cant open file" << endl;
        return 1;
    }

    string line;
    while(getline(inFile,line)){
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
