#include <iostream>
using namespace std;

void main()
{
	int t_wid, p_wid;
	int f_num, l_num;

	cin >> t_wid;
	cin >> p_wid;
	cin >> f_num;
	cin >> l_num;

	/*
	4 целых числа: 
	толщина каждого тома (без учёта переплёта), 
	толщина переплёта каждого тома, 
	номер тома, с первого листа которого червяк начал свой путь, 
	и номер тома, на последнем листе которого он остановился.
	*/
	
	cout <<
		abs( // пример: 10 1 2 1
				(l_num - f_num - 1) * (t_wid + 2 * p_wid) 

				+ 2 * p_wid
			)
		<< endl;
}