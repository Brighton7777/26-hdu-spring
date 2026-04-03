#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 500005;
const ll Mod = 998244353;

ll dp[N][2][2];
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = t.size();
    vector<bool> ss(n + 1), tt(n + 1);
    for (int i = 0; i < n - s.size(); ++i)
    {
        ss[i + 1] = 0;
        tt[i + 1] = t[i] - '0';
    }
    for (int i = n - s.size(); i < n; ++i)
    {
        ss[i + 1] = s[i - n + s.size()] - '0';
        tt[i + 1] = t[i] - '0';
    }
    ll vs = 0, vt = 0;
    for (int i = 1; i <= n; ++i)
    {
        vs = (2 * vs + ss[i]) % Mod;
        vt = (2 * vt + tt[i]) % Mod;
    }
    ll ans = vt - vs + 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= 1; ++j)
        {
            for (int k = 0; k <= 1; ++k)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int eq_s = 0; eq_s <= 1; ++eq_s)
        {
            for (int u = 0; u <= 1; ++u) // a_i = u
            {
                if (eq_s && u < ss[i])
                    continue;
                for (int eq_t = 0; eq_t <= 1; ++eq_t)
                {
                    for (int v = 0; v <= 1; ++v) // b_i = v
                    {
                        if (u > v) // a_i \le b_i
                            continue;
                        if (eq_t && v > tt[i])
                            continue;
                        int nxt_eq_s = eq_s & (u == ss[i]),
                            nxt_eq_t = eq_t & (v == tt[i]);
                        dp[i][nxt_eq_s][nxt_eq_t] += dp[i - 1][eq_s][eq_t];
                        dp[i][nxt_eq_s][nxt_eq_t] %= Mod;
                    }
                }
            }
        }
    }
    ll sum = 0;
    for (int eq_s = 0; eq_s <= 1; ++eq_s)
    {
        for (int eq_t = 0; eq_t <= 1; ++eq_t)
        {
            sum = (sum + dp[n][eq_s][eq_t]) % Mod;
        }
    }
    ans = (2 * sum - ans + Mod) % Mod;
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