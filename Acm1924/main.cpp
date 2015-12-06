/*

Мы знаем что нечетные числа имеют вид 2*k+1 
т.о. не имеет значения мы складываем или вычитаем их, результат даст четное число => 
Если дано чётное число нечетных чисел от 1 до n то ответ "black".

*/

#include <iostream>
using namespace std;

void main()
{
	int n;
	cin >> n;

	int odd_count = (n % 2) + (n / 2);

	cout << ((odd_count % 2 == 1) ? "grimy" : "black");
}