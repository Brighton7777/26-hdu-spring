#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
int p[30] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, p_cnt = 10;
int cnt[N][11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= p_cnt; ++j)
            {
                cnt[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            int x, y, gd;
            cin >> x >> y >> gd;
            for (int j = 1; j <= p_cnt; ++j)
            {
                if (gd % p[j] == 0)
                {
                    int tmp_cnt = 0;
                    while (gd % p[j] == 0)
                    {
                        gd /= p[j];
                        ++tmp_cnt;
                    }
                    cnt[x][j] = max(cnt[x][j], tmp_cnt);
                    cnt[y][j] = max(cnt[y][j], tmp_cnt);
                }
            }
        }
        for (int i = 1; i <= q; ++i)
        {
            int x, y;
            cin >> x >> y;
            long long ans = 1;
            for (int j = 1; j <= p_cnt; ++j)
            {
                long long prod = 1;
                for (int k = 1; k <= min(cnt[x][j], cnt[y][j]); ++k)
                {
                    prod *= p[j];
                }
                ans *= prod;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}