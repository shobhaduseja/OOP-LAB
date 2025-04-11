#include <iostream>
using namespace std;


class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(Vector2D& v) {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(Vector2D& v) const {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(Vector2D& v1, Vector2D& v2);
    friend ostream& operator<<(ostream& out, Vector2D& v);
};

double dotProduct(Vector2D& v1, Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ostream& operator<<(ostream& out, Vector2D& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main() {
    Vector2D a(8, 9);
    Vector2D b(3, 4);

    Vector2D sum = a + b;
    Vector2D difference = a - b;
    Vector2D scaled = a * 4.5;
    double dotP = dotProduct(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a+b: " << sum << endl;
    cout << "a-b: " << difference << endl;
    cout << "scaled: " << scaled << endl;
    cout << "dot product: " << dotP << endl;

    return 0;
}
