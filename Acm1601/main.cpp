#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	queue<string> que;

	string line;	
	while (std::getline(std::cin, line))	
		que.push(line);	


	bool next_big = true;

	while (!que.empty())
	{
		auto str = que.front();
		que.pop();
		

		for (auto i = str.begin(); i != str.end(); i++)
		{
			char ch = *i;

			if (	'!' == ch
				|| '.' == ch
				|| '?' == ch
				)
			{
				next_big = true;
				cout << ch;
				continue;
			}

			
			if (' ' == ch 
				|| '\n' == ch 
				|| '-' == ch 
				|| ':' == ch
				|| ',' == ch
				)
			{
				cout << ch;
			}
			else
			{

				if (next_big)
				{
					cout << (char)toupper(ch);
					next_big = false;					
				}
				else				
					cout << (char)tolower(ch);
				
			}
		}
		cout << endl;
	}
	return 0;
}