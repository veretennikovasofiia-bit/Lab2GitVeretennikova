#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, u;
    cout << "Введіть значення x та y: ";
    if (!(cin >> x >> y)) {
        cout << "Помилка введення даних" << endl;
        return 1;   
    }

    bool inDomain = (x >= 1 && x <= 2 && y >= 0 && y <= 2);

    if (inDomain) {
        u = sinh(y * y - cos(x));
        cout << "YES: x = " << x << ", y = " << y << endl;
        cout << "u = " << u << endl;
    } else {
        double inner_arg = sin(y + x) + 10.0;
        double ch_val = cosh(x + 1.0);
        double under_sqrt = ch_val * ch_val + 1.0;

        if (under_sqrt < 0) {
            cout << "NO: x = " << x << ", y = " << y << ". It is impossible to calculate u (sqrt error)." << endl;
            return 0;
        }
        
        u = tan(inner_arg) + sqrt(under_sqrt);
        cout << "NO: x = " << x << ", y = " << y << endl;
        cout << "u = " << u << endl;
    }
    return 0;   
}