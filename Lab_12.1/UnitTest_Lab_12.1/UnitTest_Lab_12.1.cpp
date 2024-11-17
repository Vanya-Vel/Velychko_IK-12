#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.1/Lab_12.1.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// �������� ������� ��� ��������� ��������� �����
void CreateTestFile(const char* fname, const string& content) {
    ofstream fout(fname, ios::binary);
    fout.write(content.c_str(), content.size());
    fout.close();
}

// �������� ������� ��� ���������� ����� �����
string ReadFileContent(const char* fname) {
    ifstream fin(fname, ios::binary);
    string content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    return content;
}

namespace UnitTestLab121
{
	TEST_CLASS(UnitTestLab121)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const char* inputFile = "test_input.bin";
            const char* outputFile = "test_output.bin";

            // ����� ��� ��� �����
            string inputContent = "����� ��������! �� ����.";

            // ���������� ���������
            string expectedOutput = "��� ! � �.";

            // ��������� �������� ������� ����
            CreateTestFile(inputFile, inputContent);

            // ��������� ������� ProcessBIN
            ProcessBIN(inputFile, outputFile);

            // ������ ���� ��������� �����
            string actualOutput = ReadFileContent(outputFile);

            // ���������� ���������
            Assert::AreEqual(expectedOutput, actualOutput);

            // ��������� ������ ����� (�����������)
            remove(inputFile);
            remove(outputFile);

		}
	};
}
