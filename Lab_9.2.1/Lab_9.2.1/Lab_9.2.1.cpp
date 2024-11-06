#include <iostream>
#include <cmath> // Для математичних функцій
#include <limits>

#define MAX(y, z) (((y) > (z)) ? (y) : (z)) // Макрос для знаходження найбільшого з двох чисел
#define MIN(y, z) (((y) < (z)) ? (y) : (z)) // Макрос для знаходження найменшого з двох чисел
#define ABS(x) ((x) < 0 ? -(x) : (x)) // Макрос для обчислення модуля
#define POWER(x, y) (pow((x), (y))) // Макрос для піднесення до степеня
#define CUBED(x) (POWER((x), 3)) // Макрос для кубування числа
#define PRINTI(w) puts("control output"); printf(#w " = %f\n", (w)) // Виведення дійсного числа
#define PRINTR(w) puts("result:"); printf(#w " = %f\n", (w))

using namespace std;

int main() {
    puts("Lab 9.2.1 Using macros and preprocessing directive");

    double x, y, z; // Змінні для розрахунків
    char ch; // Відповідь чи продовжувати виконання програми

    do {
        // Запит значень у користувача
        puts("x: ");
        cin >> x;
        PRINTI(x); // Виведення значення x

        puts("y: ");
        cin >> y;
        PRINTI(y); // Виведення значення y

        puts("z: ");
        cin >> z;
        PRINTI(z); // Виведення значення z

        // Обчислення
        if (z > 1 && z < 3) {
            double expr1 = MAX(ABS(x) + ABS(y) + ABS(z), POWER(x, 3));
            PRINTR(expr1); // Виведення результату
        }
        else if (z > 3) {
            double expr2 = MIN(2 * x + y, CUBED(2 * y - z));
            PRINTR(expr2); // Виведення результату
        }

        // Повторити запит
        puts("Repeat? (y/n): ");
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
