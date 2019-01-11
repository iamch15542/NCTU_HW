#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    map<string, int> tree;
    while(m > 0)
    {
        string str;
        cin>>str;
        tree[str]++;
        m--;
    }
    for(map<string, int>::iterator iter = tree.begin(); iter != tree.end(); iter++)
    {
        if(iter->second == 2)
        {
            cout<<iter->first<<'\n';
            break;
        }
    }
}