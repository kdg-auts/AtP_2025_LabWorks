#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath> // для fabs()
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

// Функція сортування одного рядка методом бульбашки
void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функція для знаходження медіани одного рядка
double findMedian(double row[], int m) {
    double temp[5];
    for (int i = 0; i < m; i++) temp[i] = row[i];

    bubbleSort(temp, m); // сортуємо копію рядка

    if (m % 2 == 1)
        return temp[m / 2];
    else
        return (temp[m / 2 - 1] + temp[m / 2]) / 2.0;
}

int main() {
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    const int n = 7;
    const int m = 5;
    double A[n][m];

    // === 1. Зчитування матриці з файлу ===
    ifstream fin("matrix_input.txt");
    if (!fin) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> A[i][j];
        }
    }
    fin.close();

    // === 2. Обчислення медіани для кожного рядка ===
    double medians[n];
    for (int i = 0; i < n; i++) {
        medians[i] = findMedian(A[i], m);
    }

    // === 3. Пошук рядків з мінімальною і максимальною медіанами ===
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (medians[i] < medians[minIndex]) minIndex = i;
        if (medians[i] > medians[maxIndex]) maxIndex = i;
    }

    // === 4. Обмін рядків місцями ===
    for (int j = 0; j < m; j++) {
        double temp = A[minIndex][j];
        A[minIndex][j] = A[maxIndex][j];
        A[maxIndex][j] = temp;
    }

    // === 5. Запис оновленої матриці у новий файл ===
    ofstream fout("matrix_output.txt");
    if (!fout) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return 1;
    }

    fout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fout << setw(8) << A[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();

    // === 6. Вивід результатів на екран ===
    cout << "Медіани по рядках:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Рядок " << i + 1 << ": " << medians[i] << endl;
    }

    cout << "\nМінімальна медіана у рядку " << minIndex + 1
         << ", максимальна — у рядку " << maxIndex + 1 << endl;

    cout << "Оновлену матрицю збережено у файл 'matrix_output.txt'" << endl;

    return 0;
}