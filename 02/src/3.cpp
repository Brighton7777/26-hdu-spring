#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 200005;
struct node
{
    ll val;
    int id;
    bool operator<(const node &x) const
    {
        if (val == x.val)
        {
            return id < x.id;
        }
        return val < x.val;
    }
};
struct seg
{
    int l;
    int r;
    node mx;
} t[N << 2];
ll a[N];
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        // cout << l << ' ' << a[l] << '\n';
        t[p].mx.val = a[l];
        t[p].mx.id = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
    return;
}
void modify(int p, int pos, ll val)
{
    if (t[p].l == t[p].r)
    {
        if (t[p].l == pos)
        {

            t[p].mx.val = val;
        }
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (pos <= mid)
        modify(p << 1, pos, val);
    else
        modify(p << 1 | 1, pos, val);
    t[p].mx = max(t[p << 1].mx, t[p << 1 | 1].mx);
    return;
}
node query(int p, int l, int r)
{
    // cout << l << ' ' << r << ' ' << t[p].l << ' ' << t[p].r << '\n';
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].mx;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (r <= mid)
        return query(p << 1, l, r);
    else if (l > mid)
        return query(p << 1 | 1, l, r);
    else
        return max(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    stack<node> s;
    for (int i = 1; i <= n - 1; ++i)
    {
        int len = i + 1;
        ll res = 0;
        // cout << i << ":\n";
        for (int l = (n / len) * len + 1; l >= 1; l -= len)
        {
            // cout << l << ' ' << n << '\n';
            if (l > n)
            {
                continue;
            }
            node x = query(1, l, n);
            // cout << x.val << '\n';
            res += x.val;
            modify(1, x.id, 0);
            s.push(x);
        }
        cout << res << ' ';
        while (!s.empty())
        {
            modify(1, s.top().id, s.top().val);
            s.pop();
        }
    }
    cout << '\n';
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