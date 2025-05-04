#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class InventoryItem{
    public:
    int ItemID;
    char ItemName[20];
    InventoryItem(){};
    InventoryItem(int id, const char* n){
        ItemID=id; 
        strncpy(ItemName, n, sizeof(ItemName)-1);
        ItemName[sizeof(ItemName)-1]='\0';
    }
};

int main(){
    InventoryItem i1(123, "fruits");
    ofstream out("inventory.dat", ios::binary);
    if(!out){
        cerr<<"Error opening file for writing!" << endl;
        return 1;
    }
    out.write(reinterpret_cast<char*>(&i1), sizeof(i1));
    out.close();


    InventoryItem i2;
    ifstream in("inventory.dat", ios::binary);
    if(!in){
        cerr<<"Error opening file forreading!" << endl;
        return 1;
    }
    in.read(reinterpret_cast<char*>(&i2), sizeof(i2));
    in.close();

    cout<<"loaded item id: "<<i2.ItemID<<endl;
    cout<<"loaded item name: "<<i2.ItemName<<endl;

    return 0;
}
