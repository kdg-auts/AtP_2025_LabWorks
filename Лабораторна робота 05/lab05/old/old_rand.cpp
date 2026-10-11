#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <windows.h> // для SetConsoleOutputCP

using namespace std;

int main() {

    // Перемикаємо консоль у UTF-8
    SetConsoleOutputCP(CP_UTF8);

    srand(time(nullptr)); // ініціалізація генератора
    //srand(42); // ініціалізація генератора

    cout << "RAND_MAX: " << RAND_MAX << endl;

    // Випадкове ціле число від 0 до RAND_MAX
    int r1 = 0;
    for (int i=0;i<10;i++) {
        r1 = rand();
        cout << "rand_full(" << i << ") = " << r1 << endl;
    }

    // Випадкове ціле число від 1 до 100
    int r2 = 0;
    for (int i=0;i<10;i++) {
        r2 = rand() % 100 + 1;
        cout << "rand_100(" << i << ") = " << r2 << endl;
    }

    // Випадкове дійсне число від 0 до 1
    double r3 = 0.0;
    for (int i=0;i<10;i++) {
        r3 = (double)rand() / RAND_MAX;
        cout << "rand_double(" << i << ") = " << r3 << endl;
    }
    
}