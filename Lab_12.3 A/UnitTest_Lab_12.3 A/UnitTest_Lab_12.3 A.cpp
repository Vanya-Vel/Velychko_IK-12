#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Для тестування використовуємо числові значення замість enum
#define ComputerScience 0
#define SoftwareEngineering 1
#define CyberSecurity 2
#define Physics 3
#define Math 4

// Оголошення структури Student
struct Student {
    int id;
    char surname[50];
    int course;
    int speciality; // Використовуємо числове значення замість enum
    int physics;
    int math;
    int informatics;
};

// Функція для створення файлу
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "Не вдалося відкрити файл для запису." << endl;
        return;
    }

    int n = 2; // Встановлюємо кількість студентів для тесту
    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;

        // Записуємо тестові дані
        strcpy_s(student.surname, "Котигорошко");
        student.course = 2;
        student.speciality = ComputerScience; // Використовуємо число замість enum
        student.physics = 5;
        student.math = 4;
        student.informatics = 5;

        fout.write((char*)&student, sizeof(student));
    }

    fout.close();
    cout << "Файл успішно створено." << endl;
}

namespace UnitTestLab123A
{
    TEST_CLASS(UnitTestLab123A)
    {
    public:

        TEST_METHOD(Test_CreateFile)
        {
            const char* filename = "test_students.bin";

            // Створюємо файл
            CreateFile(filename);

            // Перевіряємо, чи був записаний файл
            ifstream fin(filename, ios::binary);
            Assert::IsTrue(fin.is_open(), L"Не вдалося відкрити файл");

            // Читаємо дані з файлу та перевіряємо
            Student student;
            fin.read((char*)&student, sizeof(student));
            Assert::IsTrue(fin.gcount() == sizeof(student), L"Студент не був доданий");

            // Перевірка правильності даних
            Assert::AreEqual(1, student.id);
            Assert::AreEqual("Котигорошко", student.surname);
            Assert::AreEqual(2, student.course);
            Assert::AreEqual(ComputerScience, student.speciality); // Перевіряємо числове значення
            Assert::AreEqual(5, student.physics);
            Assert::AreEqual(4, student.math);
            Assert::AreEqual(5, student.informatics);

            fin.close();
        }
    };
}
