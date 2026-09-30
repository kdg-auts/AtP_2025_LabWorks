#include <iostream>
#include <limits>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8 для коректного виведення кирилиці
    SetConsoleOutputCP(CP_UTF8);
    
    // Створення масиву фіксованої розмірності
    const int size = 6;
    double numbers[size];

    // Введення 6 дійсних чисел користувачем
    cout << "Введіть 6 дійсних чисел:\n";
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }

    // Ініціалізація максимального і мінімального значення
    double max = numeric_limits<double>::lowest();
    double min = numeric_limits<double>::max();

    // Знаходження максимального і мінімального елементів масиву
    for (int i = 0; i < size; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Виведення обчислених результатів
    cout << "\n--- Результати обробки послідовності ---\n";
    cout << "Максимальний елемент: " << max << endl;
    cout << "Мінімальний елемент: " << min << endl;
    cout << "Максимальний елемент більший за мінімальний на: " << (max - min) << endl;

    return 0;
}