#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool Cmp(const pair<int, int>&l, const pair<int, int>&r)
{
    return l.second != r.second ? l.second > r.second : l.first < r.first;
}

int main(void)
{
    vector<pair<int, int>> t;
    char input;
    for(int i = 0; i < 26; i++)
    {
        t.push_back(make_pair(65 + i, 0));
    }
    while(scanf("%c", &input))
    {
        if(input == '\n')
            break;
        int b = input;
        b -= 65;
        t[b].second++;
    }
    sort(t.begin(), t.end(), Cmp);
    for(int i = 0; i < 26; i++)
    {
        if(t[i].second != 0)
            printf("%d %d\n", t[i].first, t[i].second);
    }
    return 0;
}