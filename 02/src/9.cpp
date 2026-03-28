#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 500005;
const ll INF = 1e18;

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 0 && m % 2 == 0)
    {
        if (n > m)
        {
            swap(n, m);
        }
        cout << (n * (m / 2 - 1) / 2) * 2 << '\n';
    }
    else
    {
        cout << n * m / 2 + (n * m % 2) << '\n';
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