#include <iostream>
#include <cmath>
#include <windows.h> // для SetConsoleOutputCP

int main() {
    // Встановлення української локалі для коректного виведення тексту
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "========================================================\n";
    std::cout << " Лабораторна робота №3. Приклад побудови псевдографіки\n";
    std::cout << " Рамка з діагоналями та центральним ромбом\n";
    std::cout << "========================================================\n\n";

    int N = 0;
    std::cout << "Введіть розмір сторони квадрата N (непарне число, N >= 5): ";
    if (!(std::cin >> N)) {
        std::cerr << "Помилка введення: введено неціле значення!\n";
        return 1;
    }

    // Валідація розмірності
    if (N < 5) {
        std::cout << "\nПомилка: Розмір N має бути не менше 5 для коректного відображення!\n";
        return 1;
    }

    if (N % 2 == 0) {
        std::cout << "\nПомилка: Розмір N повинен бути непарним для симетрії ромба!\n";
        return 1;
    }

    int center = N / 2;

    std::cout << "\nРезультат побудови фігури (N = " << N << "):\n\n";

    // Зовнішній цикл - перебір рядків (i)
    for (int i = 0; i < N; ++i) {
        // Внутрішній цикл - перебір стовпців (j)
        for (int j = 0; j < N; ++j) {
            // Перевірка геометричних критеріїв
            bool isBorder = (i == 0 || i == N - 1 || j == 0 || j == N - 1);
            bool isMainDiag = (i == j);
            bool isAntiDiag = (i + j == N - 1);
            bool isCenterDiamond = (std::abs(i - center) + std::abs(j - center) <= 1);

            if (isBorder || isMainDiag || isAntiDiag || isCenterDiamond) {
                std::cout << "* "; // заповнення
            } else {
                std::cout << "  "; // пробіл
            }
        }
        std::cout << '\n'; // Перехід на наступний рядок
    }

    std::cout << "\n========================================================\n";
    return 0;
}