//문제
//정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
//
//X가 3으로 나누어 떨어지면, 3으로 나눈다.
//X가 2로 나누어 떨어지면, 2로 나눈다.
//1을 뺀다.
//정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.연산을 사용하는 횟수의 최솟값을 출력하시오.
//
//입력
//첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.
//
//출력
//첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

//예시
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