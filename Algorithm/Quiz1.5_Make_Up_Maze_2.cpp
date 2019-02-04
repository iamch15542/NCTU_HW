#include <iostream>
using namespace std;
int n, m, k, arr[100001], rec[100001], ok = 0;

void run(int x, int y, int cnt)//cnt紀錄往上幾次
{
    if(y < m - 1)
    {
        if(arr[x * m + y + 1] != 0 && (rec[x * m + y + 1] == 0 || rec[x * m + y + 1] > rec[x * m + y] + 1))//當那個點的距離是0或是大於新的距離時
        {
            rec[x * m + y + 1] = rec[x * m + y] + 1;
            run(x, y + 1, cnt);
        }
    }
    if(x < n - 1)
    {
        if(arr[(x + 1) * m + y] != 0 && (rec[(x + 1) * m + y] == 0 || rec[(x + 1) * m + y] > rec[x * m + y] + 1))
        {
            rec[(x + 1) * m + y] = rec[x * m + y] + 1;
            run(x + 1, y, cnt);
        }
    }
    if(x > 0)
    {
        if(arr[(x - 1) * m + y] != 0 && (rec[(x - 1) * m + y] == 0 || rec[(x - 1) * m + y] > rec[x * m + y] + 1) && cnt < k)
        {
            rec[(x - 1) * m + y] = rec[x * m + y] + 1;
            cnt++;
            run(x - 1, y, cnt);
        }
    }
    if(x == n - 1 && y == m - 1 && rec[x * m + y] != 0)
        ok = 1;
}

int main(void)
{
    cin >> n >> m >> k;
    char input[m];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> input[j];
            if(input[j] == 'x')
                arr[i * m + j] = 0;
            else
                arr[i * m + j] = -1;
        }
    }
    run(0, 0, 0);
    if(ok)
        cout << rec[(n - 1) * m + m - 1] << '\n';
    else
        cout << "-1\n";
    return 0;
}
/*測資
6 8 2
....x...
.xx.x.x.
.xx...x.
.xxxxxx.
.xxxxxx.
........
6 9 2
.x...xxxx
.x.x.xxxx
...x.xxxx
xxxx.x...
xxxx...x.
xxxxxxxx.
*/