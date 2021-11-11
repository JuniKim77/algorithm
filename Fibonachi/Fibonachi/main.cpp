#include <cstdio>
#include <vector>

using namespace std;

vector<int> call;
vector<int> dp;

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	call[n]++;

	dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return dp[n];
}

int main()
{
	int N = 20;

	call.resize(N + 1, 0);
	dp.resize(N + 1, -1);

	printf("F(%d): %d\n", N, fibonacci(N));

	for (int i = 0; i < N; ++i)
	{
		printf("F(%d): %dÈ¸ È£Ãâ\n", i, call[i]);
	}

	return 0;
}