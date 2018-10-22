#include <iostream>
using namespace std;
const int MAXN = 1000001;

int main(void)
{
    int n, m, arr[MAXN]{};
    scanf("%d %d", &n, &m);
    for(int i = 0, a; i < n; i++)
    {
        scanf("%d", &a);
        ++arr[a];
    }
    for(int i = 0; i < MAXN - 1; i++)
        arr[i + 1] += arr[i];
    //可換成 partial_sum(arr, arr + MAXN, arr);
    int arr2[m][2];
    for(int i = 0; i < m; i++)
        cin>>arr2[i][0]>>arr2[i][1];
    for(int i = 0; i < m; i++)
        cout<<arr[arr2[i][1]] - arr[arr2[i][0] - 1]<<'\n';
}