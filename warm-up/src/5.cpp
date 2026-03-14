#include <bits/stdc++.h>

using namespace std;

const int N = 100100, K = 30;
int a[N];
long long sum[N], f[N][K]; // 在 i 处时间回溯

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }
    f[1][0] = a[1];
    f[1][k + 1] = 2 * a[1];
    for (int i = 2; i <= n; ++i)
    {
        f[i][0] = max(f[i][0], max(f[i - 1][0], f[i - 1][1]) + a[i]);
        for (int j = 1; j <= k; ++j)
            f[i][j] = max(f[i][j], f[i - 1][j + 1] + a[i] / 2);
        f[i][k + 1] = max(f[i][k + 1], max(f[i - 1][0], f[i - 1][1]) + 2 * a[i]);
        for (int j = 0; j <= k + 1; ++j)
            f[min(i + m, n)][max(0, j - m - 1)] = max(f[min(i + m, n)][max(0, j - m - 1)], f[i - 1][j] + sum[min(i + m, n)] - sum[i - 1]);
    }
    long long ans = 0;
    for (int i = 0; i <= k + 1; ++i)
        ans = max(ans, f[n][i]);
    printf("%lld\n", ans);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= k + 1; ++j)
            f[i][j] = 0;
    for (int i = 1; i <= n; ++i)
        sum[i] = 0;
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