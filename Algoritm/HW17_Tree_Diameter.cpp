#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int rec[100001];
vector<int> arr[100001];

int bfs(int init, int n)
{
    int arr2[n + 1], dis, max = rec[0];
    queue<int> q;
    q.push(init);
    memset(arr2, 0, sizeof(arr2));
    memset(rec, 0, sizeof(rec));
    arr2[init] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < arr[u].size(); ++i)
        {
            if (arr2[arr[u][i]] == 0)
            {
                arr2[arr[u][i]] = 1;
                rec[arr[u][i]] += rec[u] + 1;
                q.push(arr[u][i]);
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(rec[i] > max)
        {
            max = rec[i];
            dis = i;
        }
    }
    return dis;
}

int run(int n)
{
    int init = bfs(1, n);
    int val = bfs(init, n);
    return rec[val];
}

int main()
{
    int n, l, r, tmp;
    cin >> n;
    tmp = n;
    while(n > 1)
    {
        cin>>l>>r;
        arr[l + 1].push_back(r + 1);
        arr[r + 1].push_back(l + 1);
        n--;
    }
    cout<<run(tmp)<<'\n';
}