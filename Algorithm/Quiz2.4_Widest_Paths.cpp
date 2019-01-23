#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <tuple>
#include <queue>
#include <limits>
using namespace std;
vector<tuple<int, int, int>> tr;
vector<pair<int, int>> arr[1001];
int p[1001], r[1001], arr2[1001][1001];

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
    return (get<0>(a) > get<0>(b));
}

void init(int v)
{
    for (int i = 0; i < v; ++i)
        p[i] = i;
    memset(r, 1, sizeof(r));
}
int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
void unionc(int x, int y)
{
    p[find(x)] = find(y);
}
void kruskal(int v, int e)
{
    init(v);
    sort(tr.begin(), tr.end(), cmp);
    int i, j, x;
    for (i = 0, j = 0; i < v - 1 && j < 2*e; ++i)
    {
        while (find(get<1>(tr[j])) == find(get<2>(tr[j]))) j++;
        x = find(get<1>(tr[j]));
        unionc(get<1>(tr[j]), get<2>(tr[j]));
        arr[get<1>(tr[j])].push_back(make_pair(get<2>(tr[j]),get<0>(tr[j])));
        arr[get<2>(tr[j])].push_back(make_pair(get<1>(tr[j]),get<0>(tr[j])));
        //測試用cout << "起點：" << get<1>(tr[j]) << "終點：" << get<2>(tr[j]) << "權重：" << get<0>(tr[j]) <<'\n';
        j++;
    }
}

int bfs(int init, int end, int n)
{
    bool visit[n];
    int prev[n], mini = numeric_limits<int>::max();
    memset(visit, false, sizeof(visit));
    memset(prev, -1, sizeof(prev));
    queue<int> q;
    q.push(init);
    visit[init] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < arr[u].size(); ++i)
        {
            if (!visit[arr[u][i].first])
            {
                visit[arr[u][i].first] = true;
                prev[arr[u][i].first] = u;
                arr2[u][arr[u][i].first] = arr[u][i].second;
                if(arr[u][i].first == end)
                    break;
                q.push(arr[u][i].first);
            }
        }
    }
    for (int i = end; prev[i] != -1; i = prev[i])
        if(arr2[prev[i]][i] < mini)
            mini = arr2[prev[i]][i];
    return mini;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        tr.push_back(make_tuple(w, u, v));
        tr.push_back(make_tuple(w, v, u));
    }
    kruskal(n, m);
    for(int i = 0, x, y; i < k; ++i)
    {
        cin >> x >> y;
        cout << bfs(x, y, n)<< '\n';
    }
}
