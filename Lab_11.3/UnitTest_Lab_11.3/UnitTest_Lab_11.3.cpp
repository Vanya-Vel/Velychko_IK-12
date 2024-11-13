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
 
        
        // ���� ��� ������� addResident
        TEST_METHOD(TestAddResident)
        {
            // ��'� ����� ��� �����
            string filename = "residents.txt";

            // ��������� ������� ��������� ��������
            // ������ ��������� ����� �����������, �� ��������� input/output stream ����� ������� ���� ������������
            // ��� ���������� ����� ���������� ������� ��������
            // ��� �� �������� ��������� ��� �� ���������stringstream

            // ��������� �������� �����������
            stringstream simulatedInput;
            simulatedInput.str("Petrov\nAB\n5\n");  // �������� Petrov, ������� AB, ����� ������ 5

            // ϳ�������� simulatedInput ������ ������������ cin
            streambuf* cinbuf = cin.rdbuf();  // �������� ������ �����
            cin.rdbuf(simulatedInput.rdbuf());  // ��������������� cin �� ��� input stream

            // ��������� ������� ��������� ��������
            addResident(filename);

            // ��������� ����������� ���
            cin.rdbuf(cinbuf);

            // ����� ����������, �� �������� � ���� ������ ���
            ifstream file(filename);
            bool found = false;
            string line;

            // �������� �������� ������ � ����
            while (getline(file, line)) {
                if (line.find("Petrov") != string::npos && 
                    line.find("AB") != string::npos && 
                    line.find("5") != string::npos) {
                    found = true;
                    break;
                }
            }

            file.close();

            // ��������, �� �������� �������� ����� � ����
            Assert::IsTrue(found, L"��������� �� ��� ������� �� �����!");
        }
    };
}
