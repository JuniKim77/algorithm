#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
bool checkRightStr(const string& s);
bool checkBalancedStr(const string& s);
string devide(string& s);
string reverseStr(string s);

string solution(string p) {
	string answer = devide(p);
	return answer;
}

string devide(string& s)
{
	if (checkRightStr(s))
	{
		return s;
	}
	int count = 2;
	string u;
	string v;
	// u�� v �� ������ �и���
	while (true)
	{
		u = s.substr(0, count);
		if (checkBalancedStr(u))
		{
			v = s.substr(count);
			break;
		}
		count += 2;
	}

	if (checkRightStr(u))
	{
		u += devide(v);
		return u;
	}
	else
	{
		string ret = "(";
		ret.reserve(s.size());
		ret += devide(v);
		ret += ")";
		ret += reverseStr(u.substr(1, u.size() - 2));
		return ret;
	}
}

string reverseStr(string s)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			s[i] = ')';
		}
		else
		{
			s[i] = '(';
		}
	}
	return s;
}

bool checkBalancedStr(const string& s)
{
	unordered_map<char, int> unmap;
	for (int i = 0; i < s.size(); ++i)
	{
		// �������� �ʴ� Ű���� ȣ���� ��� ���� 0���� �����鼭 ��������
		unmap[s[i]]++;
	}
	// ���� ������ �������� ���ڿ�.
	if (unmap['('] == unmap[')'])
	{
		return true;
	}
	return false;
}
bool checkRightStr(const string& s)
{
	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		// �켱������ (���� üũ, (�� ���� ���ÿ� �߰���
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		// (�� �ƴѵ� ������ ��� �ƴϸ� ���� ������ ������.
		else if (st.empty() == false)
		{
			st.pop();
		}
		// �� ���� ���� �߸��� ���ڿ�
		else
		{
			return false;
		}
	}
	return true;
}