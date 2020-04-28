#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int N;
bool check(int combination, const vector<vector<string>>& relation);
int countBit(int num);

int solution(vector<vector<string>> relation) {
    int answer = 0;
    N = relation[0].size();
    vector<int> candiKey;
    vector<int> stk;

    for (int i = 1; i < (1 << N); ++i)
    {
        candiKey.push_back(i);
    }

    sort(candiKey.begin(), candiKey.end(), [](int a, int b)
        {
            int countA = countBit(a);
            int countB = countBit(b);
            return countA < countB;
        });

    for (auto each : candiKey)
    {
        bool poss = true;
        for (int i = 0; i < stk.size(); ++i)
        {
            int temp = each & stk[i];
            if (stk[i] == temp)
            {
                poss = false;
                break;
            }
        }

        if (poss && check(each, relation))
        {
            stk.push_back(each);
            ++answer;
        }
    }

    return answer;
}

bool check(int combination, const vector<vector<string>>& relation)
{
    int size = relation.size();
    unordered_map<string, int> m;

    for (int i = 0; i < size; ++i)
    {
        string key = "";
        for (int k = 0; k < N; ++k)
        {
            if ((combination & (1 << k)) != 0)
            {
                key.append(relation[i][k]);
            }
        }
        m[key]++;
        if (m[key] > 1)
        {
            return false;
        }
    }
    return true;
}

int countBit(int num)
{
    int count = 0;
    for (int k = 0; k < N; ++k)
    {
        if ((num & (1 << k)) != 0)
        {
            count++;
        }
    }
    return count;
}