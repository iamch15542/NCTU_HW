#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int>> tr[10001];
int rec[10001], rect[10001]; //rec紀錄0到每一個點的最短距離，rect紀錄0到每一個點的最短路徑有幾條
bool visit[10001];//紀錄有沒有去過那個點

void dijkstra(int n)
{
    for(int i = 0; i < n; ++i)
        rec[i] = 10000;
    rec[0] = 0;//0到自己的最短距離為0
    rect[0] = 1;//0到自己的條數為一條
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //讓距離最短的先跑
    pq.push(make_pair(rec[0], 0));
    while(!pq.empty())
    {
        int i = pq.top().second;
        pq.pop();
        if(visit[i])//有去過的話，就跳過
            continue;
        visit[i] = true;
        for(int j = 0; j < tr[i].size(); ++j)
        {
            if(!visit[tr[i][j].first] && rec[tr[i][j].first] > rec[i] + tr[i][j].second)
            {
                rec[tr[i][j].first] = rec[i] + tr[i][j].second;
                rect[tr[i][j].first] = rect[i];//最短路徑的條數與前一個點是相同的
                pq.push(make_pair(rec[tr[i][j].first], tr[i][j].first));
            }
            else if(!visit[tr[i][j].first] && rec[tr[i][j].first] == rec[i] + tr[i][j].second)
                rect[tr[i][j].first] += rect[i];//加上第二個點的條數
            rect[tr[i][j].first] %= 524287;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v, w; i < m; ++i)
    {
        cin >> u >> v >> w;
        tr[u].push_back(make_pair(v, w));
        tr[v].push_back(make_pair(u, w));
    }
    dijkstra(n);
    cout << rect[n - 1] % 524287 << '\n';
}