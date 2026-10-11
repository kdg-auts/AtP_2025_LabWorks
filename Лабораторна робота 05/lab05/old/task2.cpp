#include <iostream>
#include <random>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Запит у користувача діапазону
    double min, max;
    cout << "Введіть мінімальне значення діапазону: ";
    cin >> min;
    cout << "Введіть максимальне значення діапазону: ";
    cin >> max;

    // Перевірка коректності діапазону
    if (min >= max) {
        cout << "Мінімальне значення повинно бути меншим за максимальне." << endl;
        return 1;
    }

    // Ініціалізація генератора випадкових чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);

    // Створення двох масивів
    const int size = 12;
    double array1[size], array2[size];

    // Наповнення масивів випадковими дійсними числами
    for (int i = 0; i < size; ++i) {
        array1[i] = dis(gen);
        array2[i] = dis(gen);
    }

    // Виведення згенерованих масивів
    cout << "Масив 1: ";
    for (int i = 0; i < size; ++i) {
        cout << array1[i] << " ";
    }
    cout << endl;

    cout << "Масив 2: ";
    for (int i = 0; i < size; ++i) {
        cout << array2[i] << " ";
    }
    cout << endl;

    // Знаходження мінімальних елементів у кожному масиві
    int minIndex1 = 0, minIndex2 = 0;
    for (int i = 1; i < size; ++i) {
        if (array1[i] < array1[minIndex1]) {
            minIndex1 = i;
        }
        if (array2[i] < array2[minIndex2]) {
            minIndex2 = i;
        }
    }

    // Виведення мінімальних елементів
    cout << "Мінімальний елемент масиву 1: " << array1[minIndex1] << endl;
    cout << "Мінімальний елемент масиву 2: " << array2[minIndex2] << endl;

    // Обмін мінімальних елементів
    double temp = array1[minIndex1];
    array1[minIndex1] = array2[minIndex2];
    array2[minIndex2] = temp;

    // Виведення масивів після обміну
    cout << "Масив 1 після обміну: ";
    for (int i = 0; i < size; ++i) {
        cout << array1[i] << " ";
    }
    cout << endl;

    cout << "Масив 2 після обміну: ";
    for (int i = 0; i < size; ++i) {
        cout << array2[i] << " ";
    }
    cout << endl;

    return 0;
}