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
	// u와 v 로 적절히 분리함
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
		// 존재하지 않는 키값을 호출할 경우 값을 0으로 갖으면서 생성해줌
		unmap[s[i]]++;
	}
	// 수가 같으면 균혀잡힌 문자열.
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
		// 우선적으로 (인지 체크, (인 경우면 스택에 추가함
		if (s[i] == '(')
		{
			st.push(s[i]);
		}
		// (이 아닌데 안쪽이 빈게 아니면 서로 삭제가 가능함.
		else if (st.empty() == false)
		{
			st.pop();
		}
		// 그 외의 경우는 잘못된 문자열
		else
		{
			return false;
		}
	}
	return true;
}