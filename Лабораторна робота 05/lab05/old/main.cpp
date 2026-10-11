// лабораторна робота №5 - завдання 1
#include <iostream>
#include <windows.h> // для SetConsoleOutputCP
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    const int size = 9;
    double numbers[size];

    // Введення значень діапазону [min, max]
    double max, min;
    cout << "Введіть max: " << endl;
    cin >> max;
    cout << "Введіть min: " << endl;
    cin >> min;

    // init rand
    srand(time(0)); // ініціалізація генератора

    // array fill
    cout << "Array numbers: ";
    for (int i=0; i<size; i++) {
        numbers[i] = ((double)rand() / RAND_MAX)*(max-min) + min;
        cout <<  numbers[i] << " ";
    }
    cout << endl;

    // calc sum
    double sum = 0.0f;
    for (int i=0; i<size; i++) {
        if (numbers[i]<0) {
            sum += abs(numbers[i]);
        }
    }

    cout << "Sum: " << sum;

    return 0;
}