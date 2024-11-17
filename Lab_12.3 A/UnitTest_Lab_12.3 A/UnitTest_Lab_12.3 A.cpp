#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// ��� ���������� ������������� ������ �������� ������ enum
#define ComputerScience 0
#define SoftwareEngineering 1
#define CyberSecurity 2
#define Physics 3
#define Math 4

// ���������� ��������� Student
struct Student {
    int id;
    char surname[50];
    int course;
    int speciality; // ������������� ������� �������� ������ enum
    int physics;
    int math;
    int informatics;
};

// ������� ��� ��������� �����
void CreateFile(const char* filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return;
    }

    int n = 2; // ������������ ������� �������� ��� �����
    for (int i = 0; i < n; i++) {
        Student student;
        student.id = i + 1;

        // �������� ������ ���
        strcpy_s(student.surname, "�����������");
        student.course = 2;
        student.speciality = ComputerScience; // ������������� ����� ������ enum
        student.physics = 5;
        student.math = 4;
        student.informatics = 5;

        fout.write((char*)&student, sizeof(student));
    }

    fout.close();
    cout << "���� ������ ��������." << endl;
}

namespace UnitTestLab123A
{
    TEST_CLASS(UnitTestLab123A)
    {
    public:

        TEST_METHOD(Test_CreateFile)
        {
            const char* filename = "test_students.bin";

            // ��������� ����
            CreateFile(filename);

            // ����������, �� ��� ��������� ����
            ifstream fin(filename, ios::binary);
            Assert::IsTrue(fin.is_open(), L"�� ������� ������� ����");

            // ������ ��� � ����� �� ����������
            Student student;
            fin.read((char*)&student, sizeof(student));
            Assert::IsTrue(fin.gcount() == sizeof(student), L"������� �� ��� �������");

            // �������� ����������� �����
            Assert::AreEqual(1, student.id);
            Assert::AreEqual("�����������", student.surname);
            Assert::AreEqual(2, student.course);
            Assert::AreEqual(ComputerScience, student.speciality); // ���������� ������� ��������
            Assert::AreEqual(5, student.physics);
            Assert::AreEqual(4, student.math);
            Assert::AreEqual(5, student.informatics);

            fin.close();
        }
    };
}
