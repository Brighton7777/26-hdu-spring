#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 200005;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> s;
    s.push_back(n - 1);
    for (int i = 2; i <= n; ++i)
    {
        int k = i;
        ll res = 1;
        bool is_prime = true;
        for (int j = 2; j <= sqrt(k); ++j)
        {
            int cnt = 0;
            while (k % j == 0)
            {
                is_prime = false;
                ++cnt;
                k /= j;
            }
            res *= (cnt + 1);
        }
        if (k != 1)
            res <<= 1;
        --res;
        res += (n / i) - 1;
        // cout << res << " \n"[i == n];
        s.push_back(res);
    }
    sort(s.begin(), s.end());
    // for (auto x : s)
    // {
    //     cout << x << ' ';
    // }
    cout << s[n - m] << '\n';
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