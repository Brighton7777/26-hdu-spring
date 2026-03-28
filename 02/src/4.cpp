#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    k += (n - 2);
    cout << 2 << ' ' << k + 2 << ' ';
    for (int i = 1; i <= n - 2; ++i)
    {
        cout << 1 << ' ';
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