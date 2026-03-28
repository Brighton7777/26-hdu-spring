#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 500005;
const ll INF = 1e18;
struct seg
{
    int l, r;
    ll mn;
} t[N << 2];
vector<ll> sum;
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r, t[p].mn = INF;
    if (l == r)
    {
        t[p].mn = sum[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].mn = min(t[p << 1].mn, t[p << 1 | 1].mn);
    return;
}
ll query(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].mn;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
        return query(p << 1, l, r);
    else if (l > mid)
        return query(p << 1 | 1, l, r);
    return min(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
}
void solve()
{
    int n;
    cin >> n;
    sum.resize(2 * n + 5, 0);
    vector<ll> a(2 * n + 5, 0);
    for (int i = 2; i <= n + 1; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 2; i <= 2 * n + 1; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    build(1, 1, 2 * n + 1);
    for (int i = 1; i <= n + 1; ++i)
    {
        ll res = query(1, i + 1, i + n);
        if (sum[i] <= res)
        {
            cout << i << '\n';
            break;
        }
    }
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