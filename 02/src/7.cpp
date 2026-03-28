#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 500005;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1), x(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        x[i] = x[i - 1] ^ a[i];
    }
    unordered_map<int, int> cnt[2];
    ll res_zero = 0;
    ++cnt[0][0];
    for (int i = 1; i <= n; ++i)
    {
        res_zero += cnt[i & 1][x[i]];
        ++cnt[i & 1][x[i]];
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; i -= 2)
    {
        ans += i;
    }
    ans -= res_zero;
    cout << ans << ' ' << (n + 1) * n / 2 - ans << '\n';
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