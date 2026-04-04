#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(n + 1);
    ll w = k * k / 2 + 1;
    for (int i = k - 1; i >= 0; --i)
    {
        p[1] = i;
        for (int j = 2; j <= n; ++j)
        {
            p[j] = k;
            if (p[j - 1] != k)
                p[j] = min(p[j], (k * k - w) / (k - p[j - 1]));
        }
        if ((k - p[1]) * p[n] >= w)
        {
            break;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= p[i]; ++j)
        {
            cout << i - 1 << ' ';
        }
        for (int j = p[i] + 1; j <= k; ++j)
        {
            cout << n + i - 1 << ' ';
        }
    }
    cout << '\n';
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