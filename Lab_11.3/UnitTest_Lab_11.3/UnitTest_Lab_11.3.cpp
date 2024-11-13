#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../Lab_11.3/Lab_11.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab113
{
	TEST_CLASS(UnitTestLab113)
	{
    public:
 
        
        // Тест для функції addResident
        TEST_METHOD(TestAddResident)
        {
            // Ім'я файлу для тесту
            string filename = "residents.txt";

            // Викликаємо функцію додавання мешканця
            // Замість реального вводу користувача, за допомогою input/output stream можна зробити тест автоматичним
            // Для тестування можна підготувати тестове значення
            // Тут ми передаємо імітований ввід за допомогоюstringstream

            // Моделюємо введення користувача
            stringstream simulatedInput;
            simulatedInput.str("Petrov\nAB\n5\n");  // Призвище Petrov, ініціали AB, номер кімнати 5

            // Підставимо simulatedInput замість стандартного cin
            streambuf* cinbuf = cin.rdbuf();  // Зберігаємо старий буфер
            cin.rdbuf(simulatedInput.rdbuf());  // Перенаправляємо cin на наш input stream

            // Викликаємо функцію додавання мешканця
            addResident(filename);

            // Повертаємо стандартний ввід
            cin.rdbuf(cinbuf);

            // Тепер перевіряємо, чи записано в файл потрібні дані
            ifstream file(filename);
            bool found = false;
            string line;

            // Перевірка наявності запису в файлі
            while (getline(file, line)) {
                if (line.find("Petrov") != string::npos && 
                    line.find("AB") != string::npos && 
                    line.find("5") != string::npos) {
                    found = true;
                    break;
                }
            }

            file.close();

            // Перевірка, чи знайдено потрібний запис у файлі
            Assert::IsTrue(found, L"Мешканець не був доданий до файлу!");
        }
    };
}
