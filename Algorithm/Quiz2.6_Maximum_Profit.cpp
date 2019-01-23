#include <iostream>
#include <cstring>
#include <queue>
#include <limits>
typedef long long lld;
using namespace std;
int arr[102][102];
lld p = 0;

lld bfs(int n, lld prev[])
{
    int mini = numeric_limits<int>::max();
    bool visit[n];
    memset(visit, false, sizeof(visit));
    visit[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        for(int j = 0; j < n; ++j)
        {
            if(!visit[j] && arr[i][j] != 0)
            {
                visit[j] = true;
                prev[j] = i;
                q.push(j);
            }
        }
    }
    if(visit[n - 1])
    {
        for(int i = n - 1; prev[i] != -1; i = prev[i])
        {
                if(arr[prev[i]][i] < mini && arr[prev[i]][i] > 0)
                {
                    mini = arr[prev[i]][i];
                }
        }
    }
    return mini;
}

lld maxflow(int n)
{
    lld maxn = 0, parent[n];
    memset(parent, -1, sizeof(parent));
    while(bfs(n, parent) != numeric_limits<int>::max())
    {
        lld x = bfs(n, parent);
        maxn += x;
        for(int i = n - 1; i != 0; i = parent[i])
        {
            arr[parent[i]][i] -= x;
            arr[i][parent[i]] += x;
        }
    }
    return maxn;
}

int main()
{
    int n, nn, m, lo, k = 0;
    cin >> n >> nn >> m;
    lo = n + nn;
    for(k = 1; k <= n; ++k)
        cin >> arr[0][k];
    for(k = n + 1;k <= lo; ++k)
    {
        cin >> arr[k][lo + 1];
        p += arr[k][lo + 1];
    }
    for(int i = 0, u, v;i < m; ++i)
    {
        cin >> u >> v;
        arr[v][u + n] = numeric_limits<int>::max();
    }
    cout << p - maxflow(lo + 2) << '\n';
}