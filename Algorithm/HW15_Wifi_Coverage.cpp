#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int w, n;
    cin>>w>>n;
    int arr[n][2], cnt = 0, b, c = 0, d;
    vector<pair<int, int>> tr;
    for(int i = 0; i < n; ++i)
        cin>>arr[i][0]>>arr[i][1];
    for(int i = 0; i < n; ++i)
        tr.push_back(make_pair(arr[i][0] - arr[i][1], arr[i][0] + arr[i][1]));
    sort(tr.begin(), tr.end());
    if(tr[0].first > 0)
    {
        cnt = -1;
        c = 1;
    }
    b = d = 0;
    if(c == 0)
    {
        for(int i = 0; i < n; ++i)
        {
            if(d < tr[i].first)
            {
                d = b;
                cnt++;
                if(tr[i].first > d)
                    break;
            }
            if(tr[i].second > b)
                b = tr[i].second;
            if(tr[i].second >= w)
            {
                cnt++;
                break;
            }
        }
    }
    if(b < w)
        cnt = -1;
    cout<<cnt<<'\n';
}