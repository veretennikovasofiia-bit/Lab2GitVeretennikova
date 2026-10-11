#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;
    cout << "Введіть дійсні числа a, b, c, d: ";
    if (!(cin >> a >> b >> c >> d)) return 1;

    double under_x = a * a * (c + 1.0) + d;
    if (under_x < 0) {
        cout << "Помилка: неможливо обчислити x (корінь з від'ємного числа)." << endl;
        return 1;
    }
    double x = sqrt(under_x);

    double y = b - c * sqrt(4.0 + exp(d));

    double z;
    if (x > 0) {
        if (fabs(y) < 1e-9) {
            cout << "Помилка: ділення на нуль (1/y)! " << endl;
            return 1;
        }
        z = x * x - 1.0 / y;
    } else {
        z = pow(y, 3) - pow(x, 4) + 1.0;
    }

    cout << "Результат обчислення z = " << z << endl;
    return 0;
}