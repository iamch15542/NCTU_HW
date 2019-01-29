#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 100001;
int arr[MAXN], acc[MAXN], sizen[MAXN], arr2[MAXN], n, m, q, cnt = 0;
//arr紀錄disjoint set, acc紀錄是否塗黑, size紀錄disjoint set大小, arr2紀錄同樣的paint有幾次，因為倒著的時候要在最後一次塗白才對
vector<int> action[MAXN], ans; //action 紀錄動作
stack<int> rec; //紀錄還沒有答案的region的位置(因為一開始先忽略掉對白色的query())

int find(int x)
{
    return x == arr[x] ? x : (arr[x] = find(arr[x]));
}

void unionc(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)return;
    sizen[y] += sizen[x];
    arr[x] = y;
}

//搜尋上下左右是否有相同顏色的
void search(int x, int y)
{
    if(x != n)
        if(acc[x * m + y] == acc[(x - 1)*m + y])
            unionc(x * m + y, (x - 1) * m + y);
    if(x >= 2)
        if(acc[(x - 2) * m + y] == acc[(x - 1)*m + y])
            unionc((x - 2) * m + y, (x - 1)*m + y);
    if(y != m)
        if(acc[(x - 1) * m + y + 1] == acc[(x - 1) * m + y])
            unionc((x - 1) * m + y + 1, (x - 1) * m + y);
    if(y != 1)
        if(acc[(x - 1) * m + y - 1] == acc[(x - 1) * m + y])
            unionc((x - 1) * m + y - 1, (x - 1) * m + y);
}

void run()
{
    //先正著跑一次，並把對黑色的query先算出來
    for(int i = 0; i < q; ++i)
    {
        int x = action[i][1], y = action[i][2];
        if(action[i][0] == 3)
        {
            acc[(x - 1) * m + y] = 1;
            arr2[(x - 1) * m + y]++;
            search(x, y);
        }
        else if(action[i][0] == 4 && acc[(x - 1) * m + y] == 1)
        {
            ans.push_back(sizen[find((x - 1) * m + y)]);
            cnt++;
        }
        else if(action[i][0] == 4 && acc[(x - 1) * m + y] == 0)
        {
            ans.push_back(0);
            rec.push(cnt);
            cnt++;
        }
    }
    //將graph畫好，並做出disjoint set
    for(int x = 1; x <= n; ++x)
        for(int y = 1; y <= m; ++y)
            if(!acc[(x - 1) * m + y])
                search(x, y);
    //將不是白色的disjoint set變成自己一個set
    for(int i = 1; i <= n * m; ++i)
    {
        if(acc[i])
        {
            arr[i] = i;
            sizen[i] = 1;
        }
    }
    //倒著做回去，遇到paint就塗成白色的，若query的點是黑色的就忽略掉，白色的再算
    for(int i = q - 1; i >= 0; --i)
    {
        int x = action[i][1], y = action[i][2];
        if(action[i][0] == 3 && arr2[(x - 1) * m + y] == 1)
        {
            acc[(x - 1) * m + y] = 0;
            search(x, y);
        }
        else if(action[i][0] == 3 && arr2[(x - 1) * m + y] != 1)
            arr2[(x - 1) * m + y]--;
        else if(action[i][0] == 4 && acc[(x - 1) * m + y] == 1)
            continue;
        else if(action[i][0] == 4 && acc[(x - 1) * m + y] == 0)
        {
            int loc = rec.top();
            rec.pop();
            ans[loc] = sizen[find((x - 1) * m + y)];
        }
        if(rec.empty())
            break;
    }
}

int main(void)
{
    string act;
    cin >> n >> m >> q;
    for(int i = 1; i <= n * m; ++i)
    {
        arr[i] = i;
        acc[i] = 0;
        sizen[i] = 1;
    }
    for(int i = 0, x, y; i < q; ++i)
    {
        cin >> act >> x >> y;
        if(act == "paint")
        {
            action[i].push_back(3);
            action[i].push_back(x);
            action[i].push_back(y);
        }
        else if(act == "region")
        {
            action[i].push_back(4);
            action[i].push_back(x);
            action[i].push_back(y);
        }
        act.clear();
    }
    run();
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << '\n';
    return 0;
}

