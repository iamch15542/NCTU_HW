#include <iostream>
#include <algorithm>
typedef long long lld;
using namespace std;

lld check(lld arr[], lld n)
{
    lld max_sum = arr[0], ind = 0;
    for(int i = 0; i < n; ++i)
    {
        if(arr[i] >= 0)
            return -1;
        if(max_sum < arr[i])
        {
            max_sum = arr[i];
            ind = i;
        }
    }
    return ind;
}

int main()
{
    lld n, tmp = 0, ans = 0, index;
    cin>>n;
    lld arr[n], arr2[2], tmp2[2];
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    tmp2[0] = 0;
    for(int i = 0; i < n; ++i)
    {
        tmp2[1] = i;
        tmp += arr[i];
        if(tmp < 0)
        {
            tmp2[0] = i + 1;
            tmp = 0;
        }
        if(tmp > ans)
        {
            ans = tmp;
            arr2[0] = tmp2[0];
            arr2[1] = tmp2[1];
        }
    }
    index = check(arr, n);
    if(index != -1)
        arr2[0] = arr2[1] = index;
    cout<<arr2[0] + 1<<" "<<arr2[1] + 1<<'\n';
}
