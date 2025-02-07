//
  SHOBHA DUSEJA
  24K-1006
//
#include <iostream>
using namespace std;

int** createMatrice(int rows, int cols){
    int** matrice = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrice[i] = new int[cols];
    }
    cout << "Matrice is created" << endl;
    return matrice;
}


void fillingMatrice(int** matrice, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter values for the row: " << i+1 << endl;
        for (int j = 0; j < cols; j++)
        {
            cin >> matrice[i][j];
        }
    }
    cout << "Matrice are filled! " << endl << endl;
}


void addMatrices(int** matrice1, int** matrice2, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrice1[i][j] += matrice2[i][j];
        }
    }
    cout << "Matrices are Added" << endl;
}


void subtractMatrices(int** matrice1, int** matrice2, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrice1[i][j] -= matrice2[i][j];
        }
    }
    cout << "Matrices are Subtracted" << endl;
}


void displayMatrice(int** matrice1, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        cout << "| ";
        for (int j = 0; j < cols; j++)
        {
            cout << matrice1[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}


void free(int** matrice1, int** matrice2, int rows){
    for (int i = 0; i < rows; i++){
        delete[] matrice1[i];
    }
    delete[] matrice1;
    cout << endl << "Memory deleted for first matrice" << endl;
    for (int i = 0; i < rows; i++){
        delete[] matrice2[i];
    }
    delete[] matrice2;
    cout << endl << "Memory deleted for second matrice" << endl;
}


int main(){
    int rows, cols;
    cout << "Enter no of Rows: ";
    cin >> rows;
    cout << "Enter no of Cols: ";
    cin >> cols;
    int** matrice1 = createMatrice(rows, cols);
    int** matrice2 = createMatrice(rows, cols);
    fillingMatrice(matrice1, rows, cols);
    fillingMatrice(matrice2, rows, cols);
    displayMatrice(matrice1, rows, cols);
    addMatrices(matrice1, matrice2, rows, cols);
    subtractMatrices(matrice1, matrice2, rows, cols);
    displayMatrice(matrice1, rows, cols);
    free(matrice1, matrice2, rows);
    return 0;
}
