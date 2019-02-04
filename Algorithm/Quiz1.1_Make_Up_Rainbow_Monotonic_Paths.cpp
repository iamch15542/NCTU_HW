#include <iostream>
using namespace std;
int n, k, arr[102][102], ans = 0, ok = 0;

void path(int x, int y, int cnt)
{
    if(arr[x][y + 1] == cnt + 1 && !ok)
        path(x, y + 1, cnt + 1);
    if(arr[x][y + 1] == cnt && !ok)
        path(x, y + 1, cnt);
    if(arr[x + 1][y] == cnt + 1 && !ok)
        path(x + 1, y, cnt + 1);
    if(arr[x + 1][y] == cnt && !ok)
        path(x + 1, y, cnt);
    if(x == n - 1 && y == k - 1 && cnt == 7)
    {
        ans = 1;
        ok = 1;
    }
}

int main()
{
    int cnt = 1;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < k; ++j)
            cin >> arr[i][j];
    path(0, 0, cnt);
    if(ans)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}