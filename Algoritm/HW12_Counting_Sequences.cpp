#include <iostream>
#include <algorithm>
#include <cstring>
const int MODN = 1000000007;
using namespace std;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    long long arr[m], arr2[n + 1];
    memset(arr2, 0, sizeof(arr2));
    for(int i = 0; i < m; ++i)
        cin>>arr[i];
    arr2[0] = 1;
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(i + arr[j] <= n)
            {
                arr2[i+arr[j]] += arr2[i];
                arr2[i+arr[j]] %= MODN;
            }
        }
    }
    cout<< arr2[n] % MODN <<'\n';
}