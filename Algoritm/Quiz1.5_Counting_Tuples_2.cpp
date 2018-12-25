#include <iostream>
#include <unordered_map>
typedef long long ll;
const int MAXN = 1501;
using namespace std;

ll n, m, ans = 0, tmp = 0;
int arr[4][MAXN];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < n; ++j)
            cin>>arr[i][j];
    unordered_map<ll, int> tr;
    for(ll k = n - 2; k > 1; --k)
    {
        for(ll l = k + 1; l < n; ++l)
            tr[arr[2][k] + arr[3][l]]++;
        ll j = k - 1;
        for(ll i = 0; i < j; ++i)
            ans += tr[m - arr[0][i] - arr[1][j]];
    }
    cout << ans << '\n';
    return 0;
}

//參考資料
//https://blog.csdn.net/batuwuhanpei/article/details/50727227
//https://codeforces.com/blog/entry/21853