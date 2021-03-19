#include <iostream>
#include <string>

using namespace std;

bool solve(const string& str);
bool check(const string& str, int left, int right);

int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		string s;

		cin >> s;

		cout << s << endl;
	}

	return 0;
}

bool solve(const string& str)
{
	return false;
}

bool check(const string& str, int left, int right)
{
	int mid = (left + right) / 2;
	bool ret = true;

	if (left < mid)
		ret = check(str, left, mid - 1);

	if (mid < right)
		ret = check(str, mid + 1, right);

	return ret;
}
