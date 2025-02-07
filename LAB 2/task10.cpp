//
SHOBHA DUSEJA
24K-1006
//
#include <iostream>
using namespace std;

int*** createArr(int a, int b, int c){
    int*** Arr3D = new int**[a];
    for (int i = 0; i < a; i++)
    {
        Arr3D[i] = new int*[b];
        for (int j = 0; j < c; j++)
        {
            Arr3D[i][j] = new int[c];
        }
    }
    cout << "3D Array is created" << endl;
    return Arr3D;
}

void Details(int*** arr, int a, int b, int c){
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }
}

void displayArr(int*** arr, int a, int b, int c){
    cout << "given info: " << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "| ";
            for (int k = 0; k < c; k++)
            {
                cout << arr[i][j][k] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


void free(int*** arr, int a, int b){
    for (int i = 0; i < a; i++)
    {
       for (int j = 0; j < b; j++)
       {
            delete[] arr[i][j];
       }
        delete[] arr[i];
    }
}


int main(){
    int a,b,c;
    cout << "Enter size of a: ";
    cin >> a;
    cout << "Enter size of b ";
    cin >> b;
    cout << "Enter size of c: ";
    cin >> c;
    int*** arr3D = createArr(a,b,c);
    Details(arr3D,a,b,c);
    displayArr(arr3D, a,b,c);
    free(arr3D,a,b);
    return 0;
}
