#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*

�������� ������	
3 5 6
To
be
or
not
to
be

���������
2

2 �������� ������ ���:
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
		h,  // ����� �� ��������
		w,  // �������� � ������
		n;	// ���� � ������

	cin >> h >> w >> n;

	//vector<string> word(n);

	int pages = 0; // ����� �������
	int lines = 0; // �����
	int prev_len = 0; // ����� ���������� ������
	for (int i = 0; i < n; i++)
	{
		string wrd;
		cin >> wrd;
		int len = wrd.length();

		if (prev_len + 1 + len <= w)
		{
			// ���������
			prev_len += (len + 1);
			if (prev_len == w)
			{
				prev_len = 0;
				lines++;
			}
		}
		else
		{ 
			// �� ���������
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