#include <iostream>
#include <set>
typedef long long lld;
using namespace std;

int main(void)
{
    lld n, c;
    cin>>n;
    multiset<lld> tr;
    for(lld i = 0, t; i < n; ++i)
    {
        cin>>t;
        tr.insert(t);
    }
    while(tr.size() > 1)
    {
        c = *tr.begin();
        tr.erase(tr.begin());
        c += *tr.begin();
        c *=2;
        tr.erase(tr.begin());
        tr.insert(c);
    }
    cout<<*tr.begin()<<'\n';
}