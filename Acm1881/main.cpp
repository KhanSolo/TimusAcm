#include <iostream>
#include <vector>
#include <algorithm>
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
*/

int main()
{
	int 
		h,  // строк на странице
		w,  // символов в строке
		n;	// слов в тексте

	cin >> h >> w >> n;

	//vector<string> word(n);

	int pages = 0; // число страниц
	int lines = 0; // строк
	int prev_len = 0; // длина предыдущей строки
	for (int i = 0; i < n; i++)
	{
		string wrd;
		cin >> wrd;
		int len = wrd.length();

		if (prev_len + 1 + len <= w)
		{
			// уложились
			prev_len += (len + 1);
			if (prev_len == w)
			{
				prev_len = 0;
				lines++;
			}
		}
		else
		{ 
			// не уложились
			prev_len = len;
			lines++;
		}

		if (lines == h)
		{
			lines = 0;
			pages++;
		}
	}

	if (lines > 0)
		pages++;

	cout << pages;

	return 0;
}