#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int ans[10001];
bool vi[10001];
vector<pair<int, int>> arr[10001];

void dijkstra(int n)
{
    memset(ans, -1, sizeof(ans));
    priority_queue<pair<int, int>> q;
    ans[0] = 99999999;
    q.push(make_pair(ans[0], 0));
    for(int i = 0; i < n; ++i)
    {
        int a = -1;
        while (!q.empty() && vi[a = q.top().second])
            q.pop();
        if (a == -1)
            break;
        vi[a] = true;
        for(int j = 0; j < arr[a].size(); ++j)
        {
            if(!vi[arr[a][j].second] && min(arr[a][j].first, ans[a]) > ans[arr[a][j].second])
            {
                ans[arr[a][j].second] = min(arr[a][j].first, ans[a]);
                q.push(make_pair(ans[arr[a][j].second], arr[a][j].second));
            }
        }
    }
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(w, v));
        arr[v].push_back(make_pair(w, u));
    }
    dijkstra(n);
    cout<<ans[n - 1]<<'\n';
}

//參考資料
//https://stackoverflow.com/questions/18552964/finding-path-with-maximum-minimum-capacity-in-graph
//http://www.csie.ntnu.edu.tw/~u91029/Path.html#6
//https://en.wikipedia.org/wiki/Widest_path_problem