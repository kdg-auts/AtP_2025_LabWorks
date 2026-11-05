#include <iostream>
#include <cmath>
using namespace std;

// Функція перевірки простоти числа
bool isPrime(int n) {
    if (n < 2) return false;          // 0, 1, від’ємні — не прості
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false; // має дільник → не просте
    }
    return true;                      // якщо дільників не знайдено
}

int main() {
    int n;
    char choice;

    cout << "--- Програма перевірки простих чисел ---" << endl;

    do {
        // Запит вхідних даних
        cout << "\nВведіть ціле число: ";
        cin >> n;

        // Виклик функції та виведення результату
        if (isPrime(n)) {
            cout << "-> Число " << n << " є простим." << endl;
        } else {
            cout << "-> Число " << n << " НЕ є простим." << endl;
        }

        // Умова продовження циклу
        cout << "Бажаєте перевірити ще одне число? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Роботу програми завершено." << endl;

    return 0;
}