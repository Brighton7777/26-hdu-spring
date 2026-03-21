#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
int a[N], st[N][25], pos[N][25], lg[N];
void preprocess()
{
    lg[1] = 0;
    for (int i = 2; i < N; ++i)
    {
        lg[i] = lg[i / 2] + 1;
    }
}
void build_st(int n)
{
    for (int i = 1; i <= 20; ++i)
    {
        for (int j = 1; j + (1ll << i) - 1 <= n; ++j)
        {
            if (st[j][i - 1] >= st[j + (1ll << (i - 1))][i - 1])
            {
                st[j][i] = st[j][i - 1];
                pos[j][i] = pos[j][i - 1];
            }
            else
            {
                st[j][i] = st[j + (1ll << (i - 1))][i - 1];
                pos[j][i] = pos[j + (1ll << (i - 1))][i - 1];
            }
        }
    }
}
ll find_max(int l, int r)
{
    // printf("%d %d %d\n", l, r, r - l + 1);
    int k = lg[r - l + 1];
    // printf("%d\n", k);
    if (st[l][k] >= st[r - (1ll << k) + 1][k])
    {
        return pos[l][k];
    }
    else
    {
        return pos[r - (1ll << k) + 1][k];
    }
}
ll dfs(int l, int r, unordered_map<int, ll> &mp)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
    {
        ++mp[a[l]];
        return 0;
    }
    int root = find_max(l, r);
    // printf("%d\n", root);
    // printf("%d %d %d\n", l, r, root);
    if (root == l || root == r)
    {
        ll res = 0;
        if (root == l)
        {
            res = dfs(l + 1, r, mp);
        }
        else
        {
            res = dfs(l, r - 1, mp);
        }
        ++mp[a[root]];
        return res;
    }
    unordered_map<int, ll> l_mp, r_mp;
    ll res = 0;
    res += dfs(l, root - 1, l_mp);
    res += dfs(root + 1, r, r_mp);
    if (root - l < r - root)
    { // left part has less items
        mp = r_mp;
        if ((a[root] + 1) % 2 == 0)
        {
            for (int i = l; i < root; ++i)
            {
                res += r_mp[a[root] + 1 - a[i]] * 2;
            }
        }
        for (int i = l; i < root; ++i)
        {
            ++mp[a[i]];
        }
        ++mp[a[root]];
        return res;
    }
    else
    {
        mp = l_mp;
        if ((a[root] + 1) % 2 == 0)
        {
            for (int i = root + 1; i <= r; ++i)
            {
                res += l_mp[a[root] + 1 - a[i]] * 2;
            }
        }
        for (int i = root + 1; i <= r; ++i)
        {
            ++mp[a[i]];
        }
        ++mp[a[root]];
        return res;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            st[i][0] = a[i];
            pos[i][0] = i;
            for (int j = 1; j <= 20; ++j)
            {
                st[i][j] = 0, pos[i][j] = 0;
            }
        }
        build_st(n);
        // printf("%d, %d, %d, %d\n", find_max(1, 5), find_max(1, 3), find_max(1, 2), find_max(4, 5));
        unordered_map<int, ll> mp;
        ll illegel = dfs(1, n, mp);
        printf("%lld\n", n * n - illegel);
    }
    return 0;
}