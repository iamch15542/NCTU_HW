#include <iostream>
#include <set>
using namespace std;

int main(void)
{
    int d, n, c;
    cin>>d>>n;
    multiset<int> tr;
    for(int i = 0, t; i < n; ++i)
    {
        cin>>t;
        tr.insert(t);
    }
    while(tr.size() > 1)
    {
        c = * --tr.end() - d;
        tr.erase(--tr.end());
        tr.erase(--tr.end());
        tr.insert(c);
    }
    cout<<*tr.begin()<<'\n';
}