#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1);
    unordered_map<ll, ll> pre, suf;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        suf[i % m] += a[i];
    }
    ll ans = suf[k];
    for (int h = 1; h <= n; ++h)
    {
        suf[h % m] -= a[h];
        pre[h % m] += a[h];
        ans = max(ans, pre[(h + k + n * m - n) % m] + suf[(h + k) % m]);
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