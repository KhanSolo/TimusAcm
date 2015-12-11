#include <iostream>
#include <string>
using namespace std;

/*

исходные данные	
3 5 6
To
be
or
not
to
be

результат
2

2 страницы потому что:
-----
To_be
or_
not_
-----
to_be


-----

2 4 5
aa
aa
aa
aa
aa
correct answer is 3, not 2

----
aa_
aa_
----
aa_
aa_
----
aa_

----
*/

int main()
{
	int 
		h,  // строк на странице
		w,  // символов в строке
		n;	// слов в тексте

	cin >> h >> w >> n;

	int lines = 0; // начатых строк
	int prev_len = 0; // итоговая длина ранее набранной строки
	for (int i = 0; i < n; i++)
	{
		string wrd;
		cin >> wrd;
		int len = wrd.length();
		
		// начало	строки
		if (0 == prev_len)
		{
//			cout << "case 1" << endl;
			// уложились
			prev_len = len; // в начале строки пробелы не нужны

			if (prev_len == w) // строка заполнена
			{
				prev_len = 0;
			}

			lines++;
		}
		else
		{
			if (prev_len + (1 + len) <= w) // уже набранная длина + пробел + текущая
			{
//				cout << "case 2" << endl;
				// уложились
				prev_len += (1 + len);

				if (prev_len == w) // строка заполнена
				{
					prev_len = 0;
				}
			}
			else
			{
//				cout << "case 3" << endl;
				// не уложились - начали новую строку
				prev_len = len;
				lines++;
			}
		}
	}
	
	cout << lines / h + ((lines % h) ? 1 : 0);

	return 0;
}