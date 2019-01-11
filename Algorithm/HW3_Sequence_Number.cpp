//參考資料
//https://www.geeksforgeeks.org/matrix-exponentiation/
//https://kukuruku.co/post/the-nth-fibonacci-number-in-olog-n/
#include <iostream>
typedef long long lld;
const int MOD = 999999937;
using namespace std;

void multiply(lld m1[2][2], lld m2[2][2])
{
    lld tmp[2][2];
    tmp[0][0] = ((m1[0][0] * m2[0][0])%MOD + (m1[0][1] * m2[1][0])%MOD);
    tmp[0][1] = ((m1[0][0] * m2[0][1])%MOD + (m1[0][1] * m2[1][1])%MOD);
    tmp[1][0] = ((m1[1][0] * m2[0][0])%MOD + (m1[1][1] * m2[1][0])%MOD);
    tmp[1][1] = ((m1[1][0] * m2[0][1])%MOD + (m1[1][1] * m2[1][1])%MOD);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            m1[i][j] = tmp[i][j];
}

//迴圈
lld power(lld m1[2][2], lld m2[2][2], int n)
{
    if(n == 1)
        return (m1[0][0] + m1[0][1]) % MOD;
    
    power(m1, m2, n/2);
    multiply(m1, m1);
    if (n % 2 == 1)
        multiply(m1, m2);

    return (m1[0][0] + m1[0][1]) % MOD;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T > 0)
    {
        int n, arr2[32], cnt = 0;
        lld arr[2][2], arr1[2][2];
        arr[0][0] = arr1[0][0] = 1;
        arr[0][1] = arr1[0][1] =2;
        arr[1][0] = arr1[1][0] =1;
        arr[1][1] = arr1[1][1] =0;
        scanf("%d", &n);
        if(n <= 2)
            printf("1\n");
        else
        {
            n = n - 2;
            while(n > 0)
            {
                arr2[cnt] = n;
                n /= 2;
                cnt++;
            }
            lld ans = 0;
            for(int i = cnt - 2; i >= 0; i--)
            {
                multiply(arr, arr);
                if(arr2[i] % 2 != 0 && arr2[i] != 1)
                {
                    multiply(arr, arr1);
                }
            }
            ans = (arr[0][0] + arr[0][1])%MOD;
            printf("%lld\n", ans);
        }
        T--;
    }
    return 0;
}