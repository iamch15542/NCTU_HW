//http://www.csie.ntnu.edu.tw/~u91029/MaximumSubarray.html#4
//http://emn178.pixnet.net/blog/post/88907691-%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%88%97%28maximum-subarray%29
#include <iostream>
#include <cstring>
typedef long long lld;
using namespace std;

lld mcb(int *arr, int a, int mid, int b)
{
    lld lx = 0, rx = 0, ls = 0, rs = 0;
    for (int i = mid; i >= a; i--)
    {
        ls += arr[i];
        if(ls > lx)
        {
            lx = ls;
        }
    }
    for (int i = mid + 1; i <= b; i++)
    {
        rs += arr[i];
        if(rs > rx)
        {
            rx = rs;
        }
    }
    lld maxlr = lx + rx;
    if(lx > rx)
        return max(lx, maxlr);
    else
        return max(rx, maxlr);
}


lld maxsub(int *arr, int a, int b)
{
    if(a == b)
    {
        return arr[a];
    }
    int mid = (a + b) / 2;
    lld lx = maxsub(arr, a, mid);
    lld rx = maxsub(arr, mid + 1, b);
    lld cent = mcb(arr, a, mid, b);
    if(lx > rx)
        return max(lx, cent);
    else
        return max(rx, cent);
}
int main(void)
{
    int n;
    cin >> n;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    lld ans = maxsub(arr, 0, n - 1);
    if(ans < 0)
        cout<<"0"<<endl;
    else
        cout<<ans<<endl;
}
// #include <iostream>
// #include <cstring>
// typedef long long lld;
// using namespace std;

// lld maxsub(int n, int *arr)
// {
//     lld maxsum = 0, tmp = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         tmp += arr[i];
//         if (tmp < 0)
//             tmp = 0;
        
//         if (tmp > maxsum)
//             maxsum = tmp;
//     }
//     return maxsum;
// }

// int main(void)
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     memset(arr, 0, sizeof(arr));
//     for(int i = 0; i < n; i++)
//         cin>>arr[i];
//     lld ans = maxsub(n, arr);
//     if(ans < 0)
//         cout<<"0"<<endl;
//     else
//         cout<<ans<<endl;
// }
