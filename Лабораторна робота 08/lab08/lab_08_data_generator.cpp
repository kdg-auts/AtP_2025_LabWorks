#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    const int n = 7;  // кількість рядків
    const int m = 5;  // кількість стовпців
    double A[n][m];

    srand(time(0)); // ініціалізація генератора випадкових чисел

    ofstream fout("matrix_input.txt");
    if (!fout) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    // Генеруємо матрицю з випадкових дійсних чисел у діапазоні (-10; 10)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = -10 + (rand() / (double)RAND_MAX) * 20; // випадкове число (-10; 10)
            fout << setw(8) << fixed << setprecision(2) << A[i][j] << " ";
        }
        fout << endl;
    }

    fout.close();
    cout << "Матрицю успішно збережено у файл 'matrix_input.txt'" << endl;

    return 0;
}