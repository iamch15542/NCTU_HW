#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int arr[101][101], ans[101][101];

void dijkstra(int n, int x)
{
    int rec[2][n]; //分別紀錄奇數 跟 偶數條的最短路徑長度
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < n; ++j)
            rec[i][j] = -1;
    priority_queue<tuple<int, bool, int>, vector<tuple<int, bool, int>>, greater<>> pq;
    pq.emplace(0, false, x); //自己到自己最短的偶數條路徑為0, false = 偶數, true = 奇數, x = 第幾列
    while(!pq.empty())
    {
        int w = get<0>(pq.top()), u = get<2>(pq.top()); //w = 權重 u = 位置
        bool type = get<1>(pq.top()); //當前是奇數還是偶數
        pq.pop();
        if(rec[type][u] == -1) //不等於 -1時 代表找到最短路徑了
        {
            rec[type][u] = w; //最短路徑為 w 
            for(int v = 0; v < n; ++v)
            {
                //因為當前是奇數(偶數)條 所以走一條路會變成偶數(奇數)條 因此檢查偶數(奇數)條是否找到最短路徑, -1 代表還沒找到
                //若還沒找到且有路徑，便走下去
                if(rec[!type][v] == -1 && arr[u][v] != -1)
                {
                    pq.emplace(w + arr[u][v], !type, v);
                }
            }
        }
    }
    for(int i = 0; i < n; ++i)
        ans[x][i] = rec[1][i];
}

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];
    for(int i = 0; i < n; ++i)
        dijkstra(n, i);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}