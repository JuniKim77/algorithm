#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1000000000;

int N, W[16][16], dp[16][1 << 16];

int TSP(int current, int visited) {
    int& ret = dp[current][visited];
    if (ret != -1) return ret;
    // base case: ��� ������ �湮��
    if (visited == (1 << N) - 1) {
        if (W[current][0] != 0) return W[current][0];
        return IMPOSSIBLE; // ���������� �� �� ����
    }

    ret = IMPOSSIBLE;
    for (int i = 1; i < N; i++) {
        // i�� ������ �̹� �湮�߰ų� i�� ������ �� �� ����
        if (visited & (1 << i) || W[current][i] == 0) continue;
        // �� �� �ణ ������ �Ųٷ� ������ ���� ����
        // �湮�� ���� �� ������ dp�� ä�����Ƿ�, �ߺ��� ��� ����� ���ϰԵ�.
        ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i]);
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);

    memset(dp, -1, sizeof(dp));
    printf("%d\n", TSP(0, 1));
}