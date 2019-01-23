#include <iostream>
#include <algorithm>
typedef long long ll;
const int MAXN = 1501;
using namespace std;

ll n, m, ans = 0;
int arr[4][MAXN];

ll find(ll n, ll key, ll arr[])
{
    ll l = 0, r = n - 1, mid;
    while(r >= l)
    {
        mid = (l + r)/2;
        if(arr[mid] < key)
            l = mid + 1;
        else if(arr[mid] > key)
            r = mid - 1;
        else if(arr[mid] == key)
            return l;
    }
    return -1;
}

void run()
{
    ll tmp[n*n], g = 0, tmp1[n*n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            tmp[g] = arr[0][i]+arr[1][j];
            tmp1[g] = arr[2][i]+arr[3][j];
            g++;
        }
    }
    sort(tmp, tmp + g);
    sort(tmp1, tmp1 + g);
    for(int i = 0; i < g; ++i)
    {
        int c = 0;
        ll index = find(n*n, m - tmp[i], tmp1);
        if(index == -1)
            continue;
        for(ll j = index; j < g; ++j)
        {
            if(tmp[i]+tmp1[j] == m)
            {
                c++;
                ans++;
                if(tmp1[j] != tmp1[j + 1])
                    break;
            }
        }
        while(tmp[i] == tmp[i + 1])
        {
            ans += c;
            i++;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < n; ++j)
            cin>>arr[i][j];
    run();
    cout<<ans<<'\n';
    return 0;
}