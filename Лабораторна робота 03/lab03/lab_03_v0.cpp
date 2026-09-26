#include <iostream>
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {
    
    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int size;

    cout << "Введіть розмір квадрата у символах (ціле число, більше за 0): ";
    //cout << "Enter size: ";
    cin >> size;

    if (size <= 0) {
        cout << "ПОМИЛКА: розмір квадрату має бути цілим позитивним числом!";
        return 1;
    }

    cout << "Будуємо квадрат розміром " << size << "x" << size;
    cout << " з заповненим трикутником під основною діагоналлю:" << endl;

    for (int row=0; row<size; row++) {
        for (int col=0; col<size; col++) {
            // координата стопця не більше координати рядка - 
            // ми знаходимось під головною діагоналлю або на ній
            if (col<=row) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}