#include <iostream>
#include <string>
#include <map>
using namespace std;

void main()
{
	map<string, string> data;
	map<string, bool> logged;

	string  cmd, user, pass;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;

		if (cmd == "register")
		{
			cin >> user >> pass;
			if (data[user].empty())
			{
				data[user] = pass;
				cout << "success: new user added" << endl;
			}
			else			
				cout << "fail: user already exists" << endl;			

		}

		if (cmd == "login")
		{
			cin >> user >> pass;
			if (data[user].empty())
				cout << "fail: no such user" << endl;
			else
				if (pass != data[user])
					cout << "fail: incorrect password" << endl;
				else
					if (logged[user] == true)
						cout << "fail: already logged in" << endl;
					else
					{
						cout << "success: user logged in" << endl;
						logged[user] = true;
					}
		}

		if (cmd == "logout")
		{
			cin >> user;
			if (data[user].empty())
				cout << "fail: no such user" << endl;
			else
				if (logged[user] == false)
					cout << "fail: already logged out" << endl;
				else
				{
					cout << "success: user logged out" << endl;
					logged[user] = false;
				}
		}
	}	
}