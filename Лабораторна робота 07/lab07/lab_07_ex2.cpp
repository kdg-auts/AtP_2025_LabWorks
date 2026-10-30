#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <iomanip>  // setw
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

const int MAX_N = 20;
const int MAX_M = 20;

// Генерація масиву з випадковими цілими числами (у вигляді дійсних)
void generateArray(int arr[MAX_N][MAX_M], int n, int m) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Генеруємо випадкові цілі числа від -10 до 10  
            arr[i][j] = (rand() % 21 - 10);
        }
    }
}

// Виведення масиву в консоль (на екран)
void printArray(int arr[MAX_N][MAX_M], int n, int m) {
    cout << "Масив:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }
}

// Підрахунок позитивних парних елементів у рядку
int countPositiveEven(int row[MAX_M], int m) {
    int count = 0;
    for (int j = 0; j < m; j++) {
        // Перевірка: число додатне і є парним цілим
        if (row[j] > 0 && row[j] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int n, m;
    int arr[MAX_N][MAX_M];

    cout << "Введіть кількість рядків (не більше 20): ";
    cin >> n;
    cout << "Введіть кількість стовпців (не більше 20): ";
    cin >> m;

    if (n <= 0 || n > MAX_N || m <= 0 || m > MAX_M) {
        cout << "[x] Некоректний розмір масиву!" << endl;
        return 1;
    }

    // Генерація масиву
    generateArray(arr, n, m);

    // Виведення масиву
    printArray(arr, n, m);

    // Підрахунок для кожного рядка
    cout << endl;
    cout << "Кількість додатних парних елементів у рядках:" << endl;
    for (int i = 0; i < n; i++) {
        int count = countPositiveEven(arr[i], m);
        cout << "Рядок " << i + 1 << ": " << count << endl;
    }

    return 0;
}