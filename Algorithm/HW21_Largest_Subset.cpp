#include <iostream>
#include <cstring>
#include <limits>
#include <queue>
#include <utility>
typedef long long ll;
using namespace std;
ll arr[102][102];

ll bfs(int n, ll prev[])
{
    int visit[n];
    ll mini = numeric_limits<ll>::max();
    memset(visit, 0, sizeof(visit));
    queue<int> q;
    q.push(0);
    visit[0] = 1;
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        for(int j = 0; j < n; ++j)
        {
            if(visit[j] == 0 && arr[i][j] != 0)
            {
                q.push(j);
                visit[j] = 1;
                prev[j] = i;
            }
        }
    }
    if(visit[n - 1] == 1)
    {
        for (ll i = n - 1; prev[i] != -1; i = prev[i])
            if (arr[prev[i]][i] != 0 && arr[prev[i]][i] < mini)
                mini = arr[prev[i]][i];
    }
    return mini;
}


ll maximum_flow(int n)
{
    ll maxflow = 0, parent[n];
    memset(parent, -1, sizeof(parent));
    while(bfs(n, parent) != numeric_limits<ll>::max())
    {
        ll x = bfs(n, parent);
        maxflow += x;
        for(ll i = n - 1; i != 0; i = parent[i])
        {
            ll k = parent[i];
            arr[k][i] -= x;
            arr[i][k] += x;
        }
    }
    return maxflow;
}

int main(void)
{
    int n, m, u, v;
    ll p = 0;
    cin >> n >> m;
    for(int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        if( x > 0)
        {
            p += x;
            arr[i][n + 1] = x;
        }
        else
            arr[0][i] = -x;
    }
    while(m > 0)
    {
        cin >> u >> v;
        arr[v][u] = numeric_limits<ll>::max();
        m--;
    }
    cout << p - maximum_flow(n + 2) << '\n';
}


//參考資料
//http://alrightchiu.github.io/SecondRound/flow-networksmaximum-flow-ford-fulkerson-algorithm.html