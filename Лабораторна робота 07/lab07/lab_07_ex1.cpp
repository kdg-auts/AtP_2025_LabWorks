#include <iostream>
#include <cstdlib>  // для rand(), srand()
#include <ctime>    // для time()
#include <cmath>    // для fabs()
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);
    
    const int MAX = 20;
    int n, m;

    cout << "Введіть кількість рядків (не більше 20): ";
    cin >> n;
    cout << "Введіть кількість стовпців (не більше 20): ";
    cin >> m;

    if (n > MAX || m > MAX || n <= 0 || m <= 0) {
        cout << "Неправильні розміри масиву!" << endl;
        return 1;
    }

    double arr[MAX][MAX];

    // ініціалізація генератора випадкових чисел
    srand(time(0));

    cout << "\nМасив (" << n << "x" << m << "):\n";

    // Заповнення випадковими числами від -50 до 50
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // генерація значення елемента масиву
            arr[i][j] = (rand() % 101 - 50) + (rand() % 100) / 100.0; 
            // вивід елемента масиву
            cout << arr[i][j] << "\t"; 
        }
        cout << endl;
    }

    cout << "\nНомери стовпців максимальних за модулем елементів у рядках:\n";

    // Обробка рядків
    for (int i = 0; i < n; i++) {
        // шукаємо максимальне значення за модулем
        double maxAbs = fabs(arr[i][0]);
        for (int j = 1; j < m; j++) {
            if (fabs(arr[i][j]) > maxAbs) {
                maxAbs = fabs(arr[i][j]);
            }
        }

        // виводимо всі стовпці, де зустрічається maxAbs
        cout << "Рядок " << i << ": ";
        for (int j = 0; j < m; j++) {
            if (fabs(arr[i][j]) == maxAbs) {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}