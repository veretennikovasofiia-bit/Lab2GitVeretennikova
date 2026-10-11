#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double h;
    cout << "Введіть дійсне число h: ";
    if (!(cin >> h)) return 1;

    double term_sin1 = sin(h + 2);
    double term_sin2 = sin(h + 4);
    double a = exp(h) + sqrt(1.0 + h * h * term_sin1 * term_sin1 + pow(h, 4) * pow(term_sin2, 4));
    
    if (a <= 0) {
        cout << "Помилка: логарифм від невід'ємного чи нульового числа (a <= 0)." << endl;
        return 1;
    }

    double tan_h = tan(h);
    double b = log(a) - sqrt(4.0 + tan_h * tan_h + log(a) * log(a));
    double c = a * h * cosh(b * h) + b * h * sinh(a * h);

    double d = b * b - 4 * a * c;

    cout << "Коефіцієнти: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;

    if (d < 0) {
        cout << "Рівняння не має дійсних коренів." << endl;
    } else if (fabs(d) < 1e-7) {
        double x = -b / (2 * a);
        cout << "Рівняння має один дійсний корінь: x = " << x << endl;
    } else {
        double sqrt_d = sqrt(d);
        double x1 = (-b + sqrt_d) / (2 * a);
        double x2 = (-b - sqrt_d) / (2 * a);
        cout << "Рівняння має два дійсні корені:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    return 0;
}