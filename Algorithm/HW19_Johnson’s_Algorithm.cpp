#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f
int rec[1001], ans[1001][1001]; //rec紀錄各點bellman_ford後 每點的值， ans[u][v]紀錄以u為起點進行dijkstra後 u 到 v 最短的路徑長度

vector<pair<int, int>> arr3[1001]; //index為起點, pair<終點, 權重>

void bellman_ford(int n)
{
    for(int i = 0; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 0; k < arr3[j].size(); ++k)
                if(rec[arr3[j][k].first] > rec[j] + arr3[j][k].second)
                    rec[arr3[j][k].first] = rec[j] + arr3[j][k].second;
}

void dijkstra(int u, int n)
{
    int rec1[n + 1];
    bool visit[n + 1];
    memset(visit, false, sizeof(visit));
    memset(rec1, INF, sizeof(rec1));
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    rec1[u] = 0;
    pq.emplace(rec1[u], u);
    while(!pq.empty())
    {
        int t = pq.top().second;
        pq.pop();
        visit[t] = true;
        for(int i = 0; i < arr3[t].size(); ++i)
        {
            if(!visit[arr3[t][i].first] && rec1[t] + arr3[t][i].second < rec1[arr3[t][i].first])
            {
                rec1[arr3[t][i].first] = arr3[t][i].second + rec1[t];
                pq.push(make_pair(rec1[arr3[t][i].first], arr3[t][i].first));
            }
        }
    }
    for(int i = 1; i < n + 1; ++i)
    {
        if(!visit[i])
            ans[u][i] = -11;
        else
            ans[u][i] = rec1[i];
    }
}

int main()
{
    int n, m, q, u, v, w, x, y;
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        arr3[u].push_back(make_pair(v, w));
    }
    bellman_ford(n);
    for(int i = 1; i < n + 1; ++i)
        for(int j = 0; j < arr3[i].size(); ++j)
            arr3[i][j].second = arr3[i][j].second + rec[i] - rec[arr3[i][j].first];
    for(int i = 1; i < n + 1; ++i)
        dijkstra(i, n);
    for(int i = 0; i < q; ++i)
    {
        cin >> x >> y;
        if(ans[x][y] == -11)
            cout<<"no path"<<'\n';
        else
        {
            int path = ans[x][y] - rec[x] + rec[y];
            cout << path << '\n';
        }
    }
}

//參考資料
//bellman_ford
//http://www.csie.ntnu.edu.tw/~u91029/Path2.html#2
//dijkstra
//http://www.csie.ntnu.edu.tw/~u91029/Path.html#6
