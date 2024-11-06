#include <iostream>
#include <cmath> // ��� ������������ �������
#include <limits>

#define MAX(y, z) (((y) > (z)) ? (y) : (z)) // ������ ��� ����������� ���������� � ���� �����
#define MIN(y, z) (((y) < (z)) ? (y) : (z)) // ������ ��� ����������� ���������� � ���� �����
#define ABS(x) ((x) < 0 ? -(x) : (x)) // ������ ��� ���������� ������
#define POWER(x, y) (pow((x), (y))) // ������ ��� ��������� �� �������
#define CUBED(x) (POWER((x), 3)) // ������ ��� ��������� �����
#define PRINTI(w) puts("control output"); printf(#w " = %f\n", (w)) // ��������� ������� �����
#define PRINTR(w) puts("result:"); printf(#w " = %f\n", (w))

using namespace std;

int main() {
    puts("Lab 9.2.1 Using macros and preprocessing directive");

    double x, y, z; // ���� ��� ����������
    char ch; // ³������ �� ������������ ��������� ��������

    do {
        // ����� ������� � �����������
        puts("x: ");
        cin >> x;
        PRINTI(x); // ��������� �������� x

        puts("y: ");
        cin >> y;
        PRINTI(y); // ��������� �������� y

        puts("z: ");
        cin >> z;
        PRINTI(z); // ��������� �������� z

        // ����������
        if (z > 1 && z < 3) {
            double expr1 = MAX(ABS(x) + ABS(y) + ABS(z), POWER(x, 3));
            PRINTR(expr1); // ��������� ����������
        }
        else if (z > 3) {
            double expr2 = MIN(2 * x + y, CUBED(2 * y - z));
            PRINTR(expr2); // ��������� ����������
        }

        // ��������� �����
        puts("Repeat? (y/n): ");
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
