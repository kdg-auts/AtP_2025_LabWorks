#include <iostream>
#include <vector>
#include <random>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int n, min, max;
    cout << "Введіть розмір масивів N (до 10): ";
    cin >> n;
    
    if (n <= 0 || n > 10) {
        cerr << "Помилка: некоректний розмір!\n";
        return 1;
    }

    cout << "Введіть мінімальне значення діапазону: ";
    cin >> min;
    cout << "Введіть максимальне значення діапазону: ";
    cin >> max;

    if (min >= max) {
        cerr << "Помилка: мінімум має бути меншим за максимум.\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);

    // Використання векторів для динамічної розмірності
    vector<int> array1(n);
    vector<int> array2(n);

    cout << "Масив 1: ";
    for (int i = 0; i < n; ++i) {
        array1[i] = dis(gen);
        cout << array1[i] << " ";
    }
    
    cout << "\nМасив 2: ";
    for (int i = 0; i < n; ++i) {
        array2[i] = dis(gen);
        cout << array2[i] << " ";
    }
    cout << "\n";

    // Пошук індексів максимальних елементів
    int maxIdx1 = 0, maxIdx2 = 0;
    for (int i = 1; i < n; ++i) {
        if (array1[i] > array1[maxIdx1]) {
            maxIdx1 = i;
        }
        if (array2[i] > array2[maxIdx2]) {
            maxIdx2 = i;
        }
    }

    cout << "\nМаксимальний елемент масиву 1: " << array1[maxIdx1] << " (індекс " << maxIdx1 << ")\n";
    cout << "Максимальний елемент масиву 2: " << array2[maxIdx2] << " (індекс " << maxIdx2 << ")\n";

    // Заміна на нуль
    array1[maxIdx1] = 0;
    array2[maxIdx2] = 0;

    cout << "\nМасив 1 після заміни: ";
    for (int num : array1) cout << num << " ";
    
    cout << "\nМасив 2 після заміни: ";
    for (int num : array2) cout << num << " ";
    cout << endl;

    return 0;
}