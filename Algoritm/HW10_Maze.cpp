#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c = 1;
    cin>>n>>m;
    char arr[n][m];
    long long arr1[n][m];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'x')
                arr1[i][j] = 0;
            else
                arr1[i][j] = -1;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(arr1[i][0] == 0)
            c = 0;
        arr1[i][0] = c;
    }
    c = 1;
    for(int i = 0; i < m; ++i)
    {
        if(arr1[0][i] == 0)
            c = 0;
        arr1[0][i] = c;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if(arr1[i][j] == -1)
                arr1[i][j] = arr1[i - 1][j] + arr1[i][j - 1];
        }
    }
    if(arr1[n - 1][m - 1] == 0)
        cout<<"No"<<'\n';
    else
        cout<<"Yes"<<'\n';
}

