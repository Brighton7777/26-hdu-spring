#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000005;
vector<int> es[N];
ll a[N];
ll f[N], sum[N], siz[N];
ll ress[N];
bool vis[N];
ll dp(int x, int fa)
{
    vis[x] = true;
    sum[x] = a[x];
    siz[x] = 1;
    if (es[x].size() == 1 && fa != 0)
    {
        f[x] = a[x];
        return a[x];
    }
    ll mn = 1e9;
    for (auto y : es[x])
    {
        if (vis[y] == false)
        {
            ress[y] = dp(y, x);
            mn = min(mn, ress[y]);
            sum[x] += sum[y];
            siz[x] += siz[y];
        }
    }
    ll total = 0;
    for (auto y : es[x])
    {
        if (y == fa)
        {
            continue;
        }
        total += sum[y] - siz[y] * mn;
    }
    if (a[x] + total >= mn)
        return f[x] = mn;
    else
    {
        ll in = (mn - a[x] - total) / siz[x];
        ll res = min(a[x] + total + (siz[x] - 1) * in, mn - in);
        ++in;
        res = max(res, min(a[x] + total + (siz[x] - 1) * in, mn - in));
        return f[x] = res;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            es[i].clear();
            f[i] = siz[i] = sum[i] = a[i] = vis[i] = ress[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            es[u].push_back(v);
            es[v].push_back(u);
        }
        dp(1, 0);
        for (int i = 1; i <= n; ++i)
        {
            printf("%lld ", f[i]);
        }
        printf("\n");
    }
    return 0;
}