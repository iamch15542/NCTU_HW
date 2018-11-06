#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, T;
    cin>>n>>T;
    int arr[n][2];
    long long arr1[T + 1];
    memset(arr1, 0, sizeof(arr1));
    for(int i = 0; i < n; ++i)
        cin>>arr[i][0]>>arr[i][1];
    for(int i = 0; i < n; ++i)
    {
        for(int j = T; j - arr[i][0] >= 0; --j)
        {
            arr1[j] = max(arr1[j], arr1[j - arr[i][0]] + arr[i][1]);
        }
    }
    cout<<arr1[T]<<'\n';
}