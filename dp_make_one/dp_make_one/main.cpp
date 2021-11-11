//����
//���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
//
//X�� 3���� ������ ��������, 3���� ������.
//X�� 2�� ������ ��������, 2�� ������.
//1�� ����.
//���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.
//
//�Է�
//ù° �ٿ� 1���� ũ�ų� ����, 106���� �۰ų� ���� ���� N�� �־�����.
//
//���
//ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.

//����
//2 --> 1
//10 --> 3

#include <vector>
#include <algorithm>
#include <iostream>

#define MAX (1000001)

using namespace std;

int dp[MAX];
//int call[MAX];

int make_one(int n)
{
	if (n == 1)
		return 0;
	if (dp[n] != -1)
		return dp[n];

	int result = make_one(n - 1) + 1;
	if (n % 3 == 0)
		result = min(result, make_one(n / 3) + 1);
	if (n % 2 == 0)
		result = min(result, make_one(n / 2) + 1);
	dp[n] = result;
	//call[n]++;

	return result;
}

int main()
{
	int N = 10;

	//cin >> N;

	fill(dp, dp + MAX, -1);

	printf("%d\n", make_one(N));
	
	/*for (int i = 0; i < N; ++i)
	{
		printf("%d Call: %d\n", i, call[i]);
	}*/

	return 0;
}