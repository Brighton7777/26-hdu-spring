#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n, cnt, top;
int a[N + 10], lsh[N + 10], stk[N + 10];
vector<int> pos[N + 10];
int L[N + 10], R[N + 10];

int cal(int l, int r, long long v)
{
    if (l > r)
        return 0;
    int id = lower_bound(lsh + 1, lsh + cnt + 1, v) - lsh;
    if (id < 1 || cnt < id || lsh[id] != v)
        return 0;
    int pl = lower_bound(pos[id].begin(), pos[id].end(), l) - pos[id].begin();
    int pr = upper_bound(pos[id].begin(), pos[id].end(), r) - pos[id].begin();
    return pr - pl;
}

void work()
{
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        lsh[++cnt] = a[i];
        pos[i].clear();
    }
    sort(lsh + 1, lsh + cnt + 1);
    cnt = unique(lsh + 1, lsh + cnt + 1) - lsh - 1;
    for (int i = 1; i <= n; ++i)
    {
        int id = lower_bound(lsh + 1, lsh + cnt + 1, a[i]) - lsh;
        pos[id].push_back(i);
    }
    top = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (; top && a[stk[top]] < a[i]; --top)
            ;
        L[i] = top ? stk[top] + 1 : 1;
        stk[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; --i)
    {
        for (; top && a[stk[top]] <= a[i]; --top)
            ;
        R[i] = top ? stk[top] - 1 : n;
        stk[++top] = i;
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        if (!(a[i] & 1))
            continue;
        if (i - L[i] < R[i] - i)
        {
            for (int j = L[i]; j < i; ++j)
            {
                ans += cal(i + 1, R[i], a[i] + 1 - a[j]);
            }
        }
        else
        {
            for (int j = i + 1; j <= R[i]; ++j)
            {
                ans += cal(L[i], i - 1, a[i] + 1 - a[j]);
            }
        }
    }
    cout << 1LL * n * n - 2LL * ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (; T--;)
        work();
    return 0;
}