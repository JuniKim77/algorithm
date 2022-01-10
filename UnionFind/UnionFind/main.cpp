#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Find(int n);
int Merge(int left, int right);

unordered_map<string, int> net;
vector<int> parents;

int main()
{
	int T, F;
	char input[2][21];

	parents.push_back(10);
	parents.push_back(20);
	parents.push_back(50);
	parents.push_back(30);

	//sort(parents.begin(), parents.end(), [](int& a, int& b) -> bool { return a < b; });
	sort(parents.begin(), parents.end());

	auto iter = --parents.end();

	int a = *iter;

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &F);
		parents.assign(2 * F + 1, -1); //F�� ���� ���� �� �ִ� �ִ� �ο� ��
		int cnt = 1; //�̸��� ���� �ε���
		for (int j = 0; j < F; j++) {
			scanf("%s", input[0]);
			scanf("%s", input[1]);
			for (int k = 0; k < 2; k++) { //map�� ������ �ε��� �߰�
				if (net[input[k]] == 0)
					net[input[k]] = cnt++;
			}
			cout << abs(Merge(net[input[0]], net[input[1]])) << '\n'; //���Ͽ� ���� �� ������ ũ�� ���
		}
		net.clear(); //map �ʱ�ȭ
	}

	return 0;
}

int Find(int n)
{
	if (parents[n] < 0)
		return n;

	parents[n] = Find(parents[n]);

	return parents[n];
}

int Merge(int left, int right)
{
	int a = Find(left);
	int b = Find(right);

	if (a == b)
		return parents[a];

	if (parents[a] < parents[b])
	{
		parents[a] += parents[b];

		parents[b] = a;

		return parents[a];
	}
	else
	{
		parents[b] += parents[a];

		parents[a] = b;

		return parents[b];
	}
}
