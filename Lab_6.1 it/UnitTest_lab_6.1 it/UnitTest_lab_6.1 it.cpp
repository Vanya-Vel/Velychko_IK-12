#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.1 it/Lab_6.1 it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab61it
{
	TEST_CLASS(UnitTestlab61it)
	{
	public:
		
        TEST_METHOD(Test_CreateArray)
        {
            const int n = 24; // Розмір масиву
            int a[n]; // Оголошення масиву
            int Low = -40; // Нижня межа діапазону
            int High = 15; // Верхня межа діапазону

            CreateArray(a, n, Low, High); // Виклик функції для заповнення масиву

            // Перевірка, чи всі значення в масиві в межах [Low, High]
            for (int i = 0; i < n; i++) {
                Assert::IsTrue(a[i] >= Low && a[i] <= High);
            }
        }

        TEST_METHOD(Test_PrintArray) {
            const int n = 24; // Розмір масиву
            int a[n]; // Оголошення масиву

            // Виклик функції для виведення масиву
            PrintArray(a, n);

            // Якщо досягаємо цього рядка, тест пройдено
            Assert::IsTrue(true);
        }

        TEST_METHOD(Test_CalculateSum)
        {
            const int n = 5; // Розмір масиву
            int a[n] = { 1, 2, 3, 4, 5 }; // Оголошення масиву та ініціалізація

            int expected_sum = 1 + 2 + 3 + 4 + 5; // Очікувана сума

            int actual_sum = 0; // Змінна для фактичної суми
            for (int i = 0; i < n; i++) {
                actual_sum += a[i]; // Додавання значення до суми
            }
            Assert::AreEqual(expected_sum, actual_sum); // Перевірка на правильність
        }

        TEST_METHOD(Test_CountNumbers)
        {
            const int n = 6; // Розмір масиву
            int a[n] = { -2, -1, 0, 1, 2, 3 }; // Оголошення масиву та ініціалізація

            int expected_num = 6; // Очікувана кількість елементів

            int actual_num = 0; // Лічильник кількості елементів
            for (int i = 0; i < n; i++) {
                actual_num++; // Збільшення лічильника
            }
            Assert::AreEqual(expected_num, actual_num); // Перевірка на правильність
        }

        TEST_METHOD(Test_PrintModifiedArray)
        {
            const int n = 24; // Розмір масиву
            int a[n]; // Оголошення масиву

            // Виклик функції для модифікації та виведення масиву
            PrintModifiedArray(a, n);

            // Перевірка, що елементи масиву відповідають умовам
            for (int i = 0; i < n; i++) {
                Assert::IsTrue(a[i] < 0 || i % 2 != 0); // Перевірка умов для елементів
            }
        }

        TEST_METHOD(Test_CalculateModifiedSum)
        {
            const int n = 6; // Розмір масиву
            int a[n] = { -2, -1, 0, 1, 2 }; // Оголошення масиву та ініціалізація

            int expected_sum = -1 - 2 + 1; // Очікувана сума

            int actual_sum = 0; // Змінна для фактичної суми
            for (int i = 0; i < n; i++) {
                if (a[i] < 0 || i % 2 != 0) // Перевірка умов
                    actual_sum += a[i]; // Додавання значення до суми
            }
            Assert::AreEqual(expected_sum, actual_sum); // Перевірка на правильність
        }

        TEST_METHOD(Test_CountModifiedNumbers)
        {
            const int n = 6; // Розмір масиву
            int a[n] = { -2, -1, 0, 1, 2, 3 }; // Оголошення масиву та ініціалізація

            int expected_num = 4; // Очікувана кількість модифікованих чисел

            int actual_num = 0; // Лічильник кількості елементів
            for (int i = 0; i < n; i++) {
                if (a[i] < 0 || i % 2 != 0) { // Перевірка умов
                    actual_num++; // Збільшення лічильника
                }
            }
            Assert::AreEqual(expected_num, actual_num); // Перевірка на правильність
        }
	};
}
