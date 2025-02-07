//
SHOBHA DUSEJA
24k-1006
//
#include <iostream>
using namespace std;

int** createArr(int size, int size2){
    int** arr = new int*[size];
    for (int i = 0; i < size; i++){
        arr[i] = new int[size2];
    }
    cout << "array of pointers is created" << endl;
    return arr;
}

void fillArr(int** arr, int size, int size2){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            cout << "Enter integers for pointer " << i+1 << ": " << endl;;
            cin >> arr[i][j];
        }
    }
}

void displayArr(int** arr, int size, int size2){
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {  
        for(int j = 0; j < size2; j++){
            cout << arr[i][j] << ", ";
        }
    }
    cout << endl;
}

void free(int** arr, int size){
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}


int main(){
    int size, size2;
    cout << "Enter size of Array: ";
    cin >> size;
    cout << "Enter size of Elements: ";
    cin >> size2;
    int** arr = createArr(size, size2);
    fillArr(arr, size, size2);
    displayArr(arr, size, size2);
    free(arr, size);
    return 0;
}
