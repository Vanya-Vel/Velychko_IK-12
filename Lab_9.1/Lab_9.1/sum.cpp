#include <math.h>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() 
{
	n = 0;    // Ініціалізація лічильника ітерацій
	a = 1;    // Початковий член ряду для обчислення S
	s = a;    // Початкове значення суми ряду

	// Обчислення ряду до досягнення точності eps
	do {
		n++;
		dod(); // виклик процедури обчислення добутку *= R;
		s += a;
	} while (fabs(a) >= eps);  // Виконуємо, поки абсолютне значення члена ряду більше або дорівнює точності eps
}
