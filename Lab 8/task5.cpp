#include <iostream>
using namespace std;


class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0): a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(Matrix2x2 obj) {
        return Matrix2x2(a + obj.a, b + obj.b, c + obj.c, d + obj.d);
    }

    Matrix2x2 operator-(Matrix2x2 obj) {
        return Matrix2x2(a - obj.a, b - obj.b, c - obj.c, d - obj.d);
    }

    Matrix2x2 operator*(Matrix2x2 obj) {
        int r1 = a * obj.a + b * obj.c;
        int r2 = a * obj.b + b * obj.d;
        int r3 = c * obj.a + d * obj.c;
        int r4 = c * obj.b + d * obj.d;
        return Matrix2x2(r1, r2, r3, r4);
    }


    friend ostream& operator<<(ostream& out, Matrix2x2 obj) {
        out << "| " << obj.a << "  " << obj.b << " |" << endl;
        out << "| " << obj.c << "  " << obj.d << " |";
        return out;
    }


    friend int determinant(Matrix2x2& obj) {
        return (obj.a * obj.d) - (obj.b * obj.c);
    }

    friend class MatrixHelper;
};


class MatrixHelper {
public:
    static void updateelement(Matrix2x2& matrix, int row, int col, int update) {
        if (row == 0 && col == 0) {
          matrix.a = update;}
        else if (row == 0 && col == 1) {
          matrix.b = update;}
        else if (row == 1 && col == 0) {
          matrix.c = update;}
        else if (row == 1 && col == 1){
          matrix.d = update;} 
        else cout << "galat" << endl;
    }
};



int main() {
    Matrix2x2 m1(1, 8, 2, 3);
    Matrix2x2 m2(7, 6, 5, 1);

    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;

    cout << "Matrix 1:" << endl << m1 << endl;
    cout << "Matrix 2:" << endl << m2 << endl;
    cout << endl <<"Sum:" << endl << sum << endl;
    cout << endl << "Difference:" << endl << diff << endl;
    cout << endl << "Product:" << endl << prod << endl;
    cout << endl << "Determinant of Matrix 2: " <<endl <<  determinant(m2) << endl;
    cout << "Updating element at (1,2) of Matrix" << endl;
    MatrixHelper::updateElement(m1, 1, 2, 8);
    cout << "Updated Matrix:" << m1 << endl;

    return 0;
}
