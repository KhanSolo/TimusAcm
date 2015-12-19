#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	char c = input[input.size()-1];
	input.pop_back();

	int r = atoi(input.c_str());

	int answer = 0;
	// 1 - window
	// 2 - aisle
	// 3 - neither

	if (r <= 2) 
	{
		if (c == 'A' || c == 'D') 
			answer = 1;		
		else 
			answer = 2;		
	}
	else if (r <= 20) 
		{
			if (c == 'A' || c == 'F') 							
				answer = 1;			
			else 			
				answer = 2;			
		}
		else 
		{
			switch (c) 
			{
				case 'A':
				case 'K':					
					answer = 1;
					break;

				case 'C':
				case 'D':
				case 'G':
				case 'H':					
					answer = 2;
					break;

				default:					
					answer = 3;
					break;
			}
		}


	switch(answer)
	{
		case 1:
			cout << "window";
			break;

		case 2:
			cout << "aisle";
			break;

		case 3:
			cout << "neither";
			break;
	}

	return 0;
}