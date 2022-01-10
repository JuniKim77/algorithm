#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> g_graph;
vector<bool> visit;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    g_graph.assign(n + 1, {});
    visit.assign(n + 1, false);

    for (auto& each : edge)
    {
        g_graph[each[0]].push_back(each[1]);
        g_graph[each[1]].push_back(each[0]);
    }

    for (auto& each : g_graph)
    {
        for (auto& sec : each)
        {
            cout << sec << " ";
        }

        cout << endl;
    }

    queue<pair<int, int>> q;

    visit[1] = true;
    q.push({ 1, 0 });

    int deep = 0;
    int count = 0;

    while (q.empty() == false)
    {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.second > deep)
        {
            deep = cur.second;
            count = 0;
        }

        count++;

        for (auto each : g_graph[cur.first])
        {
            if (visit[each])
                continue;

            visit[each] = true;
            q.push({ each, cur.second + 1 });
        }
    }

    answer = count;

    return answer;
}

int main()
{
    int a = solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} });


    return 0;
}