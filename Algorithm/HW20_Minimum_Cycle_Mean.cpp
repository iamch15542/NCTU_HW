#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int>> arr[1001];
double rec[1002][1002];

void Bellman_Ford(int n)
{
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <=n; ++j)
            rec[i][j] = numeric_limits<double>::infinity();
    for(int i = 0; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 0; k < arr[j].size(); ++k)
                if(rec[i + 1][arr[j][k].first] > rec[i][j] + arr[j][k].second)
                    rec[i + 1][arr[j][k].first] = rec[i][j] + arr[j][k].second;
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }
    Bellman_Ford(n);
    double ans = numeric_limits<double>::infinity();;
    for(int i = 0; i <= n; ++i)
    {
        if(rec[n][i] == numeric_limits<double>::infinity())
            continue;
        double maxn = -numeric_limits<double>::infinity();
        for(int j = 0; j < n; ++j)
            maxn = max(maxn, (rec[n][i] - rec[j][i]) / (n - j));
        ans = min(ans, maxn);
    }
    cout << fixed << ans <<'\n';
}

//參考資料
//https://en.cppreference.com/w/cpp/io/manip/fixed
//http://www.csie.ntnu.edu.tw/~u91029/Cycle.html#5