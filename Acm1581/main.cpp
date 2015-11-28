#include <iostream>
#include <vector>
using namespace std;

/*
исходные данные	
8
1 1 2 3 3 3 10 10

результат
2 1 1 2 3 3 2 10

«две единицы, одна двойка, три тройки, две десятки»

*/
namespace my 
{
	class pair
	{
	public:
		int a, b;

		pair* next;
	};
}

void main()
{
	int count;
	cin >> count;

	vector<int> inp(count);	
	for (int i = 0; i < count; i++)	
		cin >> inp[i];	


	int buf = -1;
	my::pair * head = nullptr;
	my::pair * cur = nullptr;
	
	for (int i = 0; i < count;i++)
	{
		int temp = inp[i];
		if (temp != buf)
		{			
			buf = temp;
			my::pair* last = cur;

			cur = new my::pair;
			cur->a = temp;
			cur->b = 1;
			cur->next = nullptr;

			if (nullptr == head)			
				head = cur;			
			else			
				last->next = cur;			
		}
		else		
			cur->b++;		
	}

	cur = head;
	while(cur != nullptr)
	{
		cout << cur->b << " " << cur->a;
		my::pair* cur1 = cur->next;
		if (cur1 != nullptr) cout << " ";
		delete cur; //clean
		cur = cur1;
	}	
}