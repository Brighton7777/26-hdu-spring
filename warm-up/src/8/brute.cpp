#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define sll __int128
#define lld long double

constexpr ll INF = 0x7FFFFFFFFFFFFFFF;
using namespace std;

template <int ID>
struct ModInt
{
    static ll MOD;
    ll x;
    ModInt(ll n = 0)
    {
        x = n % MOD;
        if (x < 0)
            x += MOD;
    }
    ModInt qmi(ll k) const
    {
        ModInt res = 1, a = *this;
        while (k)
        {
            if (k & 1)
                res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
    ModInt inv() const { return qmi(MOD - 2); }
    ModInt &operator+=(const ModInt &b)
    {
        if ((x += b.x) >= MOD)
            x -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &b)
    {
        if ((x -= b.x) < 0)
            x += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &b)
    {
        x = x * b.x % MOD;
        return *this;
    }
    ModInt &operator/=(const ModInt &b) { return *this *= b.inv(); }
    ModInt &operator++()
    {
        if (++x == MOD)
            x = 0;
        return *this;
    }
    ModInt operator++(int)
    {
        ModInt tmp = *this;
        ++*this;
        return tmp;
    }
    ModInt &operator--()
    {
        if (x-- == 0)
            x = MOD - 1;
        return *this;
    }
    ModInt operator--(int)
    {
        ModInt tmp = *this;
        --*this;
        return tmp;
    }
    friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
    friend bool operator==(const ModInt &a, const ModInt &b) { return a.x == b.x; }
    friend bool operator!=(const ModInt &a, const ModInt &b) { return a.x != b.x; }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.x < b.x; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.x > b.x; }
    friend bool operator<=(const ModInt &a, const ModInt &b) { return a.x <= b.x; }
    friend bool operator>=(const ModInt &a, const ModInt &b) { return a.x >= b.x; }
    friend std::ostream &operator<<(std::ostream &out, const ModInt &a) { return out << a.x; }
    friend std::istream &operator>>(std::istream &in, ModInt &a)
    {
        ll t;
        in >> t;
        a = ModInt(t);
        return in;
    }
};

template <int ID>
ll ModInt<ID>::MOD = 998244353;

inline ll read()
{
    ll x = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x - 1);
}

inline void write(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}
using mint = ModInt<0>;

struct Segmenttree
{
    ll l, r;
    vector<pair<pair<ll, ll>, ll>> a;
    vector<ll> b;
    vector<ll> c;
};

Segmenttree t[50050 * 4];

ll n, q;
ll a[50050], b[50050];
ll pre;

void build(ll p, ll l, ll r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].a.push_back({{a[l], b[l]}, a[l] - b[l]});
        t[p].b.push_back(a[l]);
        t[p].c.push_back(b[l]);
        return;
    }
    ll mid = (l + r) / 2, ls = 2 * p, rs = 2 * p + 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    ll tot1 = l, tot2 = mid + 1;
    while (tot1 <= mid && tot2 <= r)
    {
        if (t[ls].a[tot1 - l].second < t[rs].a[tot2 - mid - 1].second)
        {
            t[p].a.push_back(t[ls].a[tot1 - l]);
            tot1++;
        }
        else
        {
            t[p].a.push_back(t[rs].a[tot2 - mid - 1]);
            tot2++;
        }
    }
    while (tot1 <= mid)
    {
        t[p].a.push_back(t[ls].a[tot1 - l]);
        tot1++;
    }
    while (tot2 <= r)
    {
        t[p].a.push_back(t[rs].a[tot2 - mid - 1]);
        tot2++;
    }
    t[p].b.resize(r - l + 1);
    t[p].c.resize(r - l + 1);
    for (int i = 0; i < r - l + 1; i++)
    {
        if (i == 0)
        {
            t[p].b[i] = t[p].a[i].first.first;
            continue;
        }
        t[p].b[i] = max(t[p].b[i - 1], t[p].a[i].first.first);
    }
    for (int i = r - l; i >= 0; i--)
    {
        if (i == r - l)
        {
            t[p].c[i] = t[p].a[i].first.second;
            continue;
        }
        t[p].c[i] = max(t[p].c[i + 1], t[p].a[i].first.second);
    }
}

ll ask(ll p, ll ql, ll qr, ll x, ll y)
{
    if (ql <= t[p].l && t[p].r <= qr)
    {
        ll ans = y - x;
        ll l = 0, r = t[p].a.size() - 1, pos = t[p].a.size();
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (t[p].a[mid].second > ans)
            {
                pos = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ll res = 0;
        if (pos > 0)
        {
            res = max(res, t[p].b[pos - 1] + x);
        }
        if (pos < t[p].a.size())
        {
            res = max(res, t[p].c[pos] + y);
        }
        return res;
    }
    ll mid = (t[p].l + t[p].r) / 2;
    ll res = 0;
    if (ql <= mid)
        res = max(res, ask(2 * p, ql, qr, x, y));
    if (qr > mid)
        res = max(res, ask(2 * p + 1, ql, qr, x, y));
    return res;
}

inline void solve()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read(), b[i] = read();
    }
    for (int i = 1; i <= 4 * n; i++)
    {
        t[i].a.clear();
        t[i].b.clear();
        t[i].c.clear();
    }
    pre = 0;
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        ll l = read(), r = read(), x = read() ^ pre, y = read() ^ pre;
        ll ans = ask(1, l, r, x, y);
        printf("%lld\n", ans);
        pre = ans;
    }
    return;
}

int main()
{
    ll T;
    T = read();
    while (T--)
    {
        solve();
    }
    return 0;
}
