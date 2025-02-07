// 
SHOBHA DUSEJA
24K-1006
//
#include <iostream>
#include <string>
using namespace std;

string* createString(int n){
    string* arr = new string[n];
    return arr;
}

void fillingArr(string* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter your string " << i+1 << ": ";
        getline(cin, arr[i]);
    }
}

void sortString(string* arr, int n){
    string temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
    cout << "Strings are sorted" << endl;
}

void displayString(string* arr, int n){
    for (int i = 0; i < n; i++){
        cout << "String " << i+1 << ": " << arr[i] << endl;
    }
    cout << endl;
}

void free(string* arr){
    delete[] arr;
    cout << "Memory deletd!!" << endl;
}


int main(){
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore();
    string* strarray = createString(n);
    fillingArr(strarray, n);
    displayString(strarray, n);
    sortString(strarray, n);
    displayString(strarray, n);
    free(strarray);
    return 0;
}
