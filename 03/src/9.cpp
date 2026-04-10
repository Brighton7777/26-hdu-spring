#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 100005;
struct seg
{
    ll mn;
    int l, r;
    vector<int> lt;
} t[N << 3], init[N << 3];
int a[N], ans;
int vis[N << 3];
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    t[p].lt = vector<int>();
    vis[p] = 0;
    if (l == r)
    {
        t[p].mn = a[l];
        init[p] = t[p];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].mn = min(t[p << 1].mn, t[p << 1 | 1].mn);
    init[p] = t[p];
    return;
}
void refresh(int p)
{
    if (vis[p] == ans)
        return;
    t[p] = init[p];
    vis[p] = ans;
    return;
}
void lazydown(int p)
{
    for (auto &x : t[p].lt)
    {
        if (x == -1)
        {
            t[p << 1].mn >>= 1;
            t[p << 1 | 1].mn >>= 1;
            t[p << 1].lt.push_back(-1);
            t[p << 1 | 1].lt.push_back(-1);
        }
        else
        {
            t[p << 1].mn -= x;
            t[p << 1 | 1].mn -= x;
            if (!t[p << 1].lt.empty() && t[p << 1].lt[t[p << 1].lt.size() - 1] != -1)
            {
                t[p << 1].lt[t[p << 1].lt.size() - 1] += x;
            }
            else
            {
                t[p << 1].lt.push_back(x);
            }
            if (!t[p << 1 | 1].lt.empty() && t[p << 1 | 1].lt[t[p << 1 | 1].lt.size() - 1] != -1)
            {
                t[p << 1 | 1].lt[t[p << 1 | 1].lt.size() - 1] += x;
            }
            else
            {
                t[p << 1 | 1].lt.push_back(x);
            }
        }
    }
    t[p].lt.clear();
    return;
}
void add(int p, int l, int r, int val)
{
    refresh(p);
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].mn -= val;
        if (!t[p].lt.empty() && t[p].lt[t[p].lt.size() - 1] != -1)
            t[p].lt[t[p].lt.size() - 1] += val;
        else
            t[p].lt.push_back(val);
        return;
    }
    if (t[p].l != t[p].r)
    {
        refresh(p << 1);
        refresh(p << 1 | 1);
        if (!t[p].lt.empty())
        {
            lazydown(p);
        }
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
        add(p << 1, l, r, val);
    else if (l > mid)
        add(p << 1 | 1, l, r, val);
    else
    {
        add(p << 1, l, mid, val);
        add(p << 1 | 1, mid + 1, r, val);
    }
    t[p].mn = min(t[p << 1].mn, t[p << 1 | 1].mn);
    return;
}
void div(int p, int l, int r)
{
    refresh(p);
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].mn >>= 1;
        t[p].lt.push_back(-1);
        return;
    }
    if (t[p].l != t[p].r)
    {
        refresh(p << 1);
        refresh(p << 1 | 1);
        if (!t[p].lt.empty())
        {
            lazydown(p);
        }
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
        div(p << 1, l, r);
    else if (l > mid)
        div(p << 1 | 1, l, r);
    else
    {
        div(p << 1, l, mid);
        div(p << 1 | 1, mid + 1, r);
    }
    t[p].mn = min(t[p << 1].mn, t[p << 1 | 1].mn);
    return;
}
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ans = 0;
    build(1, 1, n);
    for (int i = 1; i <= q; ++i)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int x;
            cin >> x;
            add(1, l, r, x);
        }
        else
        {
            div(1, l, r);
        }
        if (t[1].mn <= m)
        {
            ++ans;
        }
    }
    cout << ans << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
/*
2
3 1 3
5 4 6
1 1 2 4
2 2 3
1 1 3 5
3 1 3
5 4 6
1 1 2 4
2 2 3
1 1 3 5
*/