#include <iostream>
#include <fstream>
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
        cout<<line<<endl;
    }
    in.close();
    return 0;
}
