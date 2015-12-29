#include <iostream>
#include <string>

using namespace std;

string get_expr(int n)
{
	string result;

	for (int i = 0; i < n - 1; i++)
		result.push_back('(');
	
	for (int i = 1; i < n; i++) 
	{
		for (int j = 1; j <= i; j++) 
		{
			result.append("sin(");
			result.append(to_string(j));

			if (j != i) 
			{
				if (j % 2 == 1) 									
					result.push_back('-');				
				else 				
					result.push_back('+');				
			}
		}

		for (int j = 0; j < i; j++) 		
			result.push_back(')');
		
		result.push_back('+');
		result.append(to_string(n + 1 - i));
		result.push_back(')');
	}

	for (int i = 1; i <= n; i++) 
	{
		result.append("sin(");
		result.append(to_string(i));
		if (i != n) 
		{
			if (i % 2 == 1) 			
				result.push_back('-');			
			else 			
				result.push_back('+');			
		}
	}

	for (int i = 0; i < n; i++) 	
		result.push_back(')');	
		
	result.append("+1");

	return result;
}

int main()
{	
	//string str3_1 = "((sin(1)+3)sin(1-sin(2))+2)sin(1-sin(2+sin(3)))+1";
	//_ASSERT(0 == strcmp(get_expr(3).c_str(), str3_1.c_str()));

	//string str9_1 = "((((((((sin(1)+9)sin(1-sin(2))+8)sin(1-sin(2+sin(3)))+7)sin(1-sin(2+sin(3-sin(4))))+6)sin(1-sin(2+sin(3-sin(4+sin(5)))))+5)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6))))))+4)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7)))))))+3)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8))))))))+2)sin(1-sin(2+sin(3-sin(4+sin(5-sin(6+sin(7-sin(8+sin(9)))))))))+1";
	//_ASSERT(0 == strcmp(get_expr(9).c_str(), str9_1.c_str()));

	int n; 	
	cin >> n;

	cout << get_expr(n) << endl;

	return 0;
}