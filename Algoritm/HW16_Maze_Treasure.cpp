#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m, cnt = 0, c = 0, tmp, tmp1;
    cin>>n>>m;
    char arr[n][m];
    int arr3[n][2], arr4[n], arr5[n][2];
    memset(arr3, 0, sizeof(arr3));
    memset(arr4, 0, sizeof(arr4));
    memset(arr5, 0, sizeof(arr5));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'x')
            {
                arr4[i]++;
                arr3[i][1] = j;
                cnt++;
            }
            if(arr[i][j] == 'x' && c == 0)
            {
                arr3[i][0] = j;
                c++;
            }
        }
        c = 0;
    }
    for(int i = n - 1; i >= 0; --i)
    {
        if(arr4[i] != 0)
        {
            arr5[i][0] = arr3[i][1];
            arr5[i][1] = m - 1 - arr3[i][0];
            c = i;
            break;
        }
    }
    for(int i = c - 1; i >= 0; --i)
    {
        if(arr4[i] == 0)
        {
            arr5[i][0] = arr5[i + 1][0] + 1;
            arr5[i][1] = arr5[i + 1][1] + 1;
            continue;
        }
        tmp = arr3[i][1]*2;
        tmp1 = m - 1;
        arr5[i][0] = min(arr5[i + 1][0] + tmp, arr5[i + 1][1] + tmp1) + 1;
        tmp = (m - 1 - arr3[i][0])*2;
        arr5[i][1] = min(arr5[i + 1][1] + tmp, arr5[i + 1][0] + tmp1) + 1;
    }
    cout<<arr5[0][0]<<'\n';
}
