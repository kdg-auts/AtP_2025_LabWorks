#include <iostream>
#include <cmath>

using namespace std;

// Функція для обчислення n-го члена ряду
double term(int n, double x) {
    return pow(-1, n)*(pow(x, 2 * n + 1)) / (2 * n + 1);
}

int main() {
    double x, epsilon;
    cout << "Введіть x (-1 < x < 1): ";
    cin >> x;
    cout << "Введіть точність ε: ";
    cin >> epsilon;
    epsilon = fabs(epsilon); // Забезпечення того, що точність є додатним числом

    // Перевірка на допустимість x
    if (x <= -1 || x >= 1) {
        cout << "Значення x повинно бути в межах (-1, 1)." << endl;
        return 1;
    }

    double sum = 0.0;
    double currentTerm;
    int n = 0;

    // Обчислення суми ряду
    do {
        currentTerm = term(n, x);
        sum += currentTerm;
        n++;
    } while (fabs(currentTerm) >= epsilon);

    cout << "Сума ряду: " << sum << endl;
    cout << "Кількість доданків: " << n << endl;

    return 0;
}