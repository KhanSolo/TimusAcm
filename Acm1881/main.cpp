#include <iostream>
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
		h,  // ����� �� ��������
		w,  // �������� � ������
		n;	// ���� � ������

	cin >> h >> w >> n;

	int lines = 0; // ������� �����
	int prev_len = 0; // �������� ����� ����� ��������� ������
	for (int i = 0; i < n; i++)
	{
		string wrd;
		cin >> wrd;
		int len = wrd.length();
		
		// ������	������
		if (0 == prev_len)
		{
//			cout << "case 1" << endl;
			// ���������
			prev_len = len; // � ������ ������ ������� �� �����

			if (prev_len == w) // ������ ���������
			{
				prev_len = 0;
			}

			lines++;
		}
		else
		{
			if (prev_len + (1 + len) <= w) // ��� ��������� ����� + ������ + �������
			{
//				cout << "case 2" << endl;
				// ���������
				prev_len += (1 + len);

				if (prev_len == w) // ������ ���������
				{
					prev_len = 0;
				}
			}
			else
			{
//				cout << "case 3" << endl;
				// �� ��������� - ������ ����� ������
				prev_len = len;
				lines++;
			}
		}
	}
	
	cout << lines / h + ((lines % h) ? 1 : 0);

	return 0;
}