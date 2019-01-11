#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
    int n, ans = 0, dp[3000] = {0};//dp紀錄重量
    memset(dp, 9999, sizeof(dp));
    cin>>n;
    vector<pair<int, int>> tr;
    tr.push_back(make_pair(0, 0));
    dp[0] = 0;
    for(int i = 0, a, b; i < n; ++i)
    {
        cin>>a>>b;
        tr.push_back(make_pair(b, a)); // 第一個是存可以承受重量 第二個是存自己的重量
    }
    sort(tr.begin(), tr.end()); //承受重量有小排到大
    for(int i = 1; i <= n; ++i)
    {
        for(int j = ans + 1; j > 0; --j)
        {
            if(dp[j] > dp[j - 1] + tr[i].second && tr[i].first > dp[j - 1] + tr[i].second) //確認下一個可以承受上面的重量
            {
                dp[j] = dp[j - 1] + tr[i].second;
                if(ans < j)
                    ans = j;
            }
        }
    }
    cout<<ans<<'\n';
}
