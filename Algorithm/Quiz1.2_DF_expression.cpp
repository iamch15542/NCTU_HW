#include <iostream>
using namespace std;
const int MAXN = 1500000;

char input[MAXN];
int ans = 0, i = -1;

void run(int n)
{
    int cnt = 0;
    while(1)
    {
        i++;
        if(input[i] == '2')
        {
            run(n/2);
            cnt++;
        }
        else if(input[i] == '1')
        {
            ans += n * n;
            cnt++;
        }
        else if(input[i] == '0')
            cnt++;
        if(cnt == 4 || input[i] == '\0')
            break;
    }
}

int main(void)
{
    int n;
    cin>>n;
    cin>>input;
    run(n);
    cout << ans << '\n';
}

