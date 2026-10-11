// генерація випадкових цілих чисел у вказаному діапазоні
#include <iostream>
#include <random>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Ініціалізація генератора випадкових чисел
    random_device rd;  // Отримуємо випадкове число з апаратного генератора
    mt19937 gen(rd());  // Створюємо генератор на основі певного алгоритму генерації псевдовипадкового числа

    // Визначення діапазону
    int min = -50;
    int max = 50;

    // Створення розподілу
    uniform_int_distribution<> dis(min, max);

    // Генерація і виведення випадкового цілого числа
    int random_integer = dis(gen);
    cout << "Випадкове ціле число: " << random_integer << endl;

    return 0;
}