#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 5005;
const ll Mod = 998244353;
ll fac[N], ifac[N];
ll qpower(ll a, ll b)
{
    ll base = a, res = 1;
    while (b)
    {
        if (b & 1)
            res = res * base % Mod;
        base = base * base % Mod;
        b >>= 1;
    }
    return res;
}
void preprocess()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        fac[i] = fac[i - 1] * i % Mod;
    }
    ifac[N - 1] = qpower(fac[N - 1], Mod - 2);
    for (int i = N - 2; i >= 0; --i)
    {
        ifac[i] = ifac[i + 1] * (i + 1) % Mod;
    }
    return;
}
ll c(ll n, ll r)
{
    return (fac[n] * ifac[n - r] % Mod) * ifac[r] % Mod;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    ll mn = a[0], mx = a[0];
    ll res = 0;
    for (int i = 1; i < n; ++i)
    {
        if (mn <= (a[i] - mx))
        {
            // cout << i << ' ' << mn << '\n';
            // cout << a[i] << ' ' << mn << '\n';
            res = (res + c(a[i], mn)) % Mod;
        }
        else
        {
            res = (res + c(a[i], mx)) % Mod;
        }
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cout << res << '\n';
    return;
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
        solve();
    }

    return 0;
}