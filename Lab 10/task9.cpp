#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("large_log.txt", ios::in);
    if(!in){
        cerr<<"Error: can't open file!";
        return 1;
    }
    char str[11];
    str[10]='\0';


    in.read(str,10);
    cout<<str<<endl;
    cout<<"Current position: "<<in.tellg()<<endl;
    in.read(str, 10);
    str[in.gcount()] = '\0';
    cout<<str<<endl;
    cout<<"Current position: "<<in.tellg()<<endl;
    in.close();
    return 0;
}
