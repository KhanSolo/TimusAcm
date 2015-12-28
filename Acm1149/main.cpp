﻿
/*

Пусть An = sin(1–sin(2+sin(3–sin(4+...sin(n))...)

Обозначим Sn = (...(A1+n)A2+n–1)A3+...+2)An+1

Для заданного N выведите выражение SN
Исходные данные
В единственной строке дано целое число N. 1 ≤ N ≤ 200



исходные данные	

3



результат

((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1

--------------------------------------------------
	(
		(sin(1)+3) * sin(1–sin(2)) + 2
	) 
	* 
	sin(1–sin(2+sin(3)))+1

-----------------------------------------------------

9
((((((((sin(1)+9)sin(1-sin(2))+8)sin(1-sin(2+sin(3)))+7)sin(1-sin(2+sin(3-sin(4))))+6)sin(1-sin(2+sin(3-sin(4+sin(5)))))+5)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6))))))+4)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7)))))))+3)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8))))))))+2)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8+sin(9)))))))))+1

*/
#include <iostream>
#include <string>

using namespace std;


string get_expr(int n)
{

	return nullptr;
}

int main()
{
	_ASSERT(get_expr(3) == "((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1");
	_ASSERT(get_expr(9) == "((((((((sin(1)+9)sin(1-sin(2))+8)sin(1-sin(2+sin(3)))+7)sin(1-sin(2+sin(3-sin(4))))+6)sin(1-sin(2+sin(3-sin(4+sin(5)))))+5)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6))))))+4)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7)))))))+3)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8))))))))+2)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8+sin(9)))))))))+1");

	int n; 	cin >> n;

	cout << get_expr(n) << endl;

	return 0;
}