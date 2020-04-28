#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int m[5000][5000];
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    memset(m, 0, sizeof(m));
    map<int, int> xTable;
    map<int, int> yTable;

    for (int i = 0; i < data.size(); ++i)
    {
        xTable[data[i][0]] = 0;
        yTable[data[i][1]] = 0;
    }

    int count = 0;
    for (auto iter = xTable.begin(); iter != xTable.end(); ++iter)
    {
        iter->second = count++;
    }

    count = 0;
    for (auto iter = yTable.begin(); iter != yTable.end(); ++iter)
    {
        iter->second = count++;
    }

    for (int i = 0; i < data.size(); ++i)
    {
        data[i][0] = xTable[data[i][0]];
        data[i][1] = yTable[data[i][1]];

        m[data[i][1]][data[i][0]] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            m[i][j] += ((i - 1 >= 0 ? m[i - 1][j] : 0)
                + (j - 1 >= 0 ? m[i][j - 1] : 0)
                - (i - 1 >= 0 && j - 1 >= 0 ? m[i - 1][j - 1] : 0));
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (data[i][0] == data[j][0] || data[i][1] == data[j][1])
            {
                continue;
            }

            int startX = min(data[i][0], data[j][0]);
            int startY = min(data[i][1], data[j][1]);
            int endX = max(data[i][0], data[j][0]);
            int endY = max(data[i][1], data[j][1]);

            int count;

            if (startX + 1 == endX || startY + 1 == endY)
            {
                count = 0;
            }
            else
            {
                count = m[endY - 1][endX - 1] - m[endY - 1][startX] - m[startY][endX - 1] + m[startY][startX];
            }

            if (count == 0)
            {
                answer++;
            }
        }
    }

    return answer;
}