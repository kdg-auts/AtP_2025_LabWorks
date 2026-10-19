#include <iostream>
#include <cmath>

using namespace std;

// Функція для обчислення n-го члена ряду
double calculateTerm(int n, double x) {
    if (n == 0)
        return 1;
    else
        return (pow(-1, n) * pow(x, 2*n)) / (n * 2);
}

int main() {
    double x, epsilon;
    cout << "Введіть x (-1 < x < 1): ";
    cin >> x;
    cout << "Введіть точність ε: ";
    cin >> epsilon;

    // Перевірка на правильність введення x
    if (x <= -1 || x >= 1) {
        cout << "Значення x повинно бути в межах (-1, 1)." << endl;
        return 1;
    }

    double sum = 0.0;
    double term;
    int n = 0;
    int count = 0;

    // Обчислення суми ряду
    do {
        term = calculateTerm(n, x);
        sum += term;
        count++;
        n++;
    } while (fabs(term) >= epsilon); // Продовжувати, поки член ряду більший за ε

    // Виведення результатів
    cout << "Сума ряду: " << sum << endl;
    cout << "Кількість доданків: " << count << endl;

    return 0;
}