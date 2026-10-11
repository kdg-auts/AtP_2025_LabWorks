#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double min, max;
    cout << "Введіть мінімальне значення діапазону: ";
    cin >> min;
    cout << "Введіть максимальне значення діапазону: ";
    cin >> max;

    if (min >= max) {
        cerr << "Помилка: мінімальне значення повинно бути меншим за максимальне.\n";
        return 1;
    }

    // Ініціалізація сучасного генератора випадкових чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);

    const int size = 7;
    double numbers[size];

    // Наповнення масиву
    cout << "Згенерований масив: ";
    for (int i = 0; i < size; ++i) {
        numbers[i] = dis(gen);
        cout << numbers[i] << " ";
    }
    cout << "\n";

    double sum_of_squares = 0.0;
    
    // Використання діапазонного циклу (C++11)
    for (double num : numbers) {
        if (num > 0) {
            sum_of_squares += (num * num);
        }
    }

    cout << "Сума квадратів додатних елементів: " << sum_of_squares << endl;
    return 0;
}