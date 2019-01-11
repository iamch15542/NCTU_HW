#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
    int n, m, s;
    cin >> n >> m >> s;
    int arr[n], k = m - s, total = 0;
    int arr2[k + 1];
    memset(arr2, 0, sizeof(arr2));
    for(int i = 0; i < n; ++i)
    {
        cin>>arr[i];
        total += arr[i];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = k; j >= arr[i]; --j)
        {
            arr2[j] = max(arr2[j], arr2[j - arr[i]] + arr[i]);
        }
    }
    if(total <= k)
        cout<<"0\n";
    else
        cout<<total - arr2[k]<<'\n';
}
//參考資料
//http://www.csie.ntnu.edu.tw/~u91029/KnapsackProblem.html