#include <iostream>
using namespace std;

void build(int tree[][2], int *a, int index, int l, int r)
{
    if(l == r)
    {
        tree[index][0] = a[l];
        tree[index][1] = l;
        return;
    }
    int m = (l + r) / 2;
    build(tree, a, 2 * index, l, m);
    build(tree, a, 2 * index + 1, m + 1, r);
    tree[index][0] = max(tree[2 * index][0], tree[2 * index + 1][0]);
    if(tree[2 * index][0] > tree[2 * index + 1][0])
        tree[index][1] = tree[2 * index][1];
    else if(tree[2 * index][0] < tree[2 * index + 1][0])
        tree[index][1] = tree[2 * index + 1][1];
    else
        tree[index][1] = min(tree[2 * index][1], tree[2 * index + 1][1]);
    return;
}

int query(int tree[][2], int index, int front, int end, int l, int r)
{
    if(l > end || front > r)
        return -1;
    
    if(front >= l && end <= r)
        return index;
    int m = (front + end)/2;
    int lc = query(tree, 2 * index, front, m, l, r);
    int rc = query(tree, 2 * index + 1, m + 1, end, l, r);
    if(lc == -1)
        return rc;
    else if(rc == -1)
        return lc;
    if(tree[lc][0] > tree[rc][0])
        return lc;
    else if(tree[lc][0] == tree[rc][0])
    {
        if(tree[lc][1] < tree[rc][1])
            return lc;
        else
            return rc;
    }
    else
        return rc;
}

int main(void)
{
    int n, m, ans;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int (*tree)[2] = new int[4 * n + 1][2];
    build(tree, arr, 1, 0, n - 1);
    while(m > 0)
    {
        int l, r;
        cin >> l >> r;
        ans = query(tree, 1, 0, n - 1, l - 1, r - 1);
        cout <<tree[ans][1] + 1<< endl;
        m--;
    }
    return 0;
}