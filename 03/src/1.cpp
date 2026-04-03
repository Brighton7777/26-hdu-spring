#include <bits/stdc++.h>
#define ll long long
#define i128 __int128_t
using namespace std;
const int N = 200005;
const ll INF = 1e18 + 7;
void solve()
{
    ll n, tmp;
    cin >> n >> tmp;
    i128 m = tmp;
    vector<i128> a(n), b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        a[i] = tmp;
    }
    for (int i = 0; i < n + 1; ++i)
    {
        cin >> tmp;
        b[i] = tmp;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<i128> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] += pre[i];
        pre[i + 1] += a[i] * b[i];
    }
    if (pre[n] >= m)
    {
        cout << "0\n";
        return;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        suf[n - i] += suf[n - i - 1];
        suf[n - i] += a[i] * b[i + 1];
    }
    ll ans = INF;
    for (int i = n; i >= 0; --i)
    {
        i128 p = pre[i], s = suf[n - i];
        i128 gap = m - p - s;
        ll new_a = gap / b[i] + ((gap % b[i]) != 0);
        if ((i == 0 || new_a <= a[i - 1]) && (i == n || new_a >= a[i]))
        {
            // cout << i << ' ' << gap << ' ' << new_a << '\n';
            ans = min(ans, new_a);
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
1
3 46
5 3 1
4 3 2 1

*/