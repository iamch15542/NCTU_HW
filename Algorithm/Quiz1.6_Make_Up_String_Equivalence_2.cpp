#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string find(string s, unsigned long n)
{
    string sl1, sr1;
    if(s.length() % 2 == 0)
    {
        sl1.assign(s, 0, n/2);
        sr1.assign(s, n/2, n);
        sl1 = find(sl1, n/2);
        sr1 = find(sr1, n/2);
        if(!lexicographical_compare(sl1.begin(), sl1.end(), sr1.begin(), sr1.end()))
            swap_ranges(sl1.begin(), sl1.end(), sr1.begin());
        s = sl1 + sr1;
    }
    return s;
}

int main(void)
{
    string str, ans;
    cin >> str;
    unsigned long strlong = str.length();
    ans = find(str, strlong);
    cout << ans << '\n';
    return 0;
}