#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef pair<char, int> pp;

int main()
{
	int n; 	cin >> n;

	map<char, int> box = {
		pp('A', 1),
		pp('B', 2),
		pp('D', 3),
		pp('G', 3),
		pp('J', 3),
		pp('K', 3),
		pp('M', 2),
		pp('O', 1),
		pp('P', 1),
		pp('R', 1),
		pp('S', 2),
		pp('T', 3),
		pp('W', 3),
	};

	int steps = 0;
	int cur_box = 1;
	for (int i = 0; i < n; i++)
	{
		string name; cin >> name;
		auto letter = name[0];
		int new_box = box[letter];
		if (new_box != cur_box)
		{
			steps+=abs(new_box-cur_box);
			cur_box = new_box;
		}
	}

	cout << steps << endl;

	return 0;
}