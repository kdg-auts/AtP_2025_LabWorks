// генерація випадкових дійсних чисел у вказаному діапазоні
#include <iostream>
#include <random>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Ініціалізація генератора випадкових чисел
    random_device rd;  // Отримуємо випадкове число з апаратного генератора
    mt19937 gen(rd());  // Створюємо генератор на основі випадкового числа

    // Визначення діапазону
    double min = -50.0;
    double max = 10.0;

    // Створення розподілу
    uniform_real_distribution<> dis(min, max);

    // Генерація і виведення випадкового дійсного числа
    double random_real = dis(gen);
    cout << "Випадкове дійсне число: " << random_real << endl;

    return 0;
}