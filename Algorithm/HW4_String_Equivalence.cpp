#include <iostream>
#include <string>
#include <algorithm> //reverse 用的標頭檔
using namespace std;

bool cmp(string a1, string a2, unsigned long n)
{
    string str1l, str1r, str2l, str2r;
    if(a1.length() % 2 != 0)
    {
        if(a1 == a2)
            return true;
        //不需要翻轉
        // reverse(a1.begin(), a1.end());
        // if(a1 == a2)
        //     return true;
        // reverse(a1.begin(), a1.end());
    }
    else
    {
        str1l.assign(a1, 0, n/2);
        str1r.assign(a1, n/2, n);
        str2l.assign(a2, 0, n/2);
        str2r.assign(a2, n/2, n);
        if(cmp(str1l, str2l, n/2) && cmp(str1r, str2r, n/2))
            return true;
        else if(cmp(str1l, str2r, n/2) && cmp(str1r, str2l, n/2))
            return true;
    }
    return false;
}
int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;
    unsigned long strlong = str1.length();
    if(cmp(str1, str2, strlong))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
