#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() 
{
	n = 0;    // ����������� ��������� ��������
	a = 1;    // ���������� ���� ���� ��� ���������� S
	s = a;    // ��������� �������� ���� ����

	// ���������� ���� �� ���������� ������� eps
	do {
		n++;
		dod(); // ������ ��������� ���������� ������� *= R;
		s += a;
	} while (fabs(a) >= eps);  // ��������, ���� ��������� �������� ����� ���� ����� ��� ������� ������� eps
}
