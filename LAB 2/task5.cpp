//
SHOBHA DUSEJA
24K-1006
//
#include <iostream>
using namespace std;

int* createArr(int n){
    int* Arr = new int[n];
    cout << "Array is created" << endl;
    return Arr;
}

void fillArr(int* Arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Integer " << i+1 << ": " << endl;
        cin >> Arr[i];
    }
}

void displayArr(int* Arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Integer " << i+1 << ": " << *(Arr + i) << endl;
    }
}

void Sum(int* Arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(Arr + i);
    }
    cout << "Sum of integers is : " << sum << endl;
}

void free(int* Arr){
    delete[] Arr;
    cout << endl << "Memory deleted" << endl;
}


int main(){
    int size;
    cout << "Enter number of integers: ";
    cin >> size;
    int* array = createArr(size);
    fillArr(array, size);
    displayArr(array, size);
    Sum(array, size);
    free(array);
    
    return 0;
}
