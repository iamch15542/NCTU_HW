#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int n;
    char m[2];
    cin >> n;
    scanf("%c", &m[0]);
    scanf("%c", &m[1]);
    while(n > 0)
    {
        int a;
        char b[1];
        map<string, int> tree;
        scanf("%d", &a);
        scanf("%c", &b[0]);
        while(a > 0)
        {
            string str, str2;
            int cnt = 0;
            getline(cin, str);
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] == 'A' || str[i] == 'B' || str[i] == 'C')
                {
                    str2 += '2';
                    cnt++;
                }
                else if(str[i] == 'D' || str[i] == 'E' || str[i] == 'F')
                {
                    str2 += '3';
                    cnt++;
                }
                else if(str[i] == 'G' || str[i] == 'H' || str[i] == 'I')
                {
                    str2 += '4';
                    cnt++;
                }
                else if(str[i] == 'J' || str[i] == 'K' || str[i] == 'L')
                {
                    str2 += '5';
                    cnt++;
                }
                else if(str[i] == 'M' || str[i] == 'N' || str[i] == 'O')
                {
                    str2 += '6';
                    cnt++;
                }
                else if(str[i] == 'P' || str[i] == 'R' || str[i] == 'S')
                {
                    str2 += '7';
                    cnt++;
                }
                else if(str[i] == 'T' || str[i] == 'U' || str[i] == 'V')
                {
                    str2 += '8';
                    cnt++;
                }
                else if(str[i] == 'W' || str[i] == 'X' || str[i] == 'Y')
                {
                    str2 += '9';
                    cnt++;
                }
                else if(int(str[i]) < 58 && int(str[i]) > 47)
                {
                    str2 += str[i];
                    cnt++;
                }
                if(cnt == 3)
                {
                    str2 += '-';
                    cnt++;
                }
            }
            tree[str2] += 1;
            str2.clear();
            a--;
        }
        map<string, int>::iterator iter;
        int ans = 0;
        for(iter = tree.begin(); iter != tree.end(); iter++)
        {
            if(iter->second > 1)
            {
                ans++;
                cout<<iter->first<<" "<<iter->second<<'\n';
            }
        }
        if(ans == 0)
            cout<<"No duplicate."<<'\n'<<'\n';
        
        n--;
    }
}