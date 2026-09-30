#include <iostream>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Налаштовуємо виведення українських символів у консолі Windows
    SetConsoleOutputCP(CP_UTF8);

    const int size = 6;
    double numbers[size];

    cout << "Введіть 6 дійсних чисел (через пробіл або Enter):\n";
    for (int i = 0; i < size; ++i) {
        if (!(cin >> numbers[i])) {
            cerr << "Помилка: введено некоректні дані! Очікувалося дійсне число.\n";
            return 1;
        }
    }

    // Ініціалізуємо екстремуми першим фактично введеним числом
    double max = numbers[0];
    double min = numbers[0];

    // Пошук починаємо з другого елемента (індекс 1)
    for (int i = 1; i < size; ++i) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    // Виведення результатів
    cout << "\n--- Результати обробки ---\n";
    cout << "Максимальний елемент: " << max << "\n";
    cout << "Мінімальний елемент: " << min << "\n";
    cout << "Максимальний елемент більший за мінімальний на: " << (max - min) << "\n";

    return 0;
}