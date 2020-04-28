#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;
class Trie
{
public:
    Trie()
        : mCount(0)
    {
        memset(mNext, 0, sizeof(mNext));
    }
    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
        {
            if (mNext[i] != nullptr)
            {
                delete mNext[i];
            }
        }
    }
    void insert(const char* s)
    {
        if (s == nullptr || *s == '\0')
        {
            return;
        }

        int idx = *s - 'a';
        if (mNext[idx] == nullptr)
        {
            mNext[idx] = new Trie();
        }
        mNext[idx]->mCount++;
        mNext[idx]->insert(s + 1);
    }
    int find(const char* s)
    {
        if (*s == '?')
        {
            int count = 0;
            for (int i = 0; i < 26; ++i)
            {
                if (mNext[i] == nullptr)
                {
                    continue;
                }
                count += mNext[i]->mCount;
            }
            return count;
        }

        int idx = *s - 'a';
        if (mNext[idx] == nullptr)
        {
            return 0;
        }
        return mNext[idx]->find(s + 1);
    }
private:
    int mCount;
    Trie* mNext[26];
};

void reverseStr(string& s);

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    unordered_map<int, Trie> wLists;
    unordered_map<int, Trie> wReLists;
    for (auto each : words)
    {
        wLists[each.size()].insert(each.c_str());
        reverseStr(each);
        wReLists[each.size()].insert(each.c_str());
    }
    for (auto each : queries)
    {
        int num;
        if (each[0] == '?')
        {
            reverseStr(each);
            num = wReLists[each.size()].find(each.c_str());
        }
        else
        {
            num = wLists[each.size()].find(each.c_str());
        }

        answer.push_back(num);
    }

    return answer;

}

void reverseStr(string& s)
{
    int begin = 0;
    int end = s.size() - 1;

    while (begin < end)
    {
        int temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
}