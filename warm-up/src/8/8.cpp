#include <bits/stdc++.h>

using namespace std;

const int N = 100005, SN = 1005;
long long a[N], b[N];
int blk[N], l[N], r[N];
long long pre_mx_a[N]; // a
long long suf_mx_b[N]; // b
struct clothes
{
    long long a, b, d; // delta price = a - b
    bool operator<(const clothes &x) const
    {
        return d < x.d;
    }
};
vector<clothes> blk_cs[SN];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    int blk_len = sqrt(n);
    for (int i = 1; i <= n; ++i)
    {
        int blk_id = (i - 1) / blk_len + 1;
        blk[i] = blk_id;
        blk_cs[blk_id].push_back((clothes){a[i], b[i], a[i] - b[i]});
        if (blk[i] != blk[i - 1])
        {
            r[blk[i - 1]] = i - 1;
            l[blk[i]] = i;
        }
    }
    r[blk[n]] = n;
    int blk_idx = blk[n];
    for (int i = 1; i <= blk_idx; ++i)
    {
        sort(blk_cs[i].begin(), blk_cs[i].end());
        pre_mx_a[l[i]] = blk_cs[i][0].a;
        for (int j = 1; j <= r[i] - l[i]; ++j)
        {
            pre_mx_a[l[i] + j] = max(pre_mx_a[l[i] + j - 1], blk_cs[i][j].a);
        }
        suf_mx_b[r[i]] = blk_cs[i][r[i] - l[i]].b;
        for (int j = r[i] - l[i] - 1; j >= 0; --j)
        {
            suf_mx_b[l[i] + j] = max(suf_mx_b[l[i] + j + 1], blk_cs[i][j].b);
        }
    }

    long long ans = 0, lst_ans = 0;
    for (int i = 1; i <= q; ++i)
    {
        int L, R;
        long long X, Y;
        cin >> L >> R >> X >> Y;
        long long x = X ^ lst_ans, y = Y ^ lst_ans;
        ans = 0;
        int l_blk = blk[L], r_blk = blk[R];
        if (l_blk == r_blk)
        {
            for (int j = L; j <= R; ++j)
            {
                ans = max(ans, min(a[j] + x, b[j] + y));
            }
        }
        else
        {
            for (int j = L; j <= r[l_blk]; ++j)
            {
                ans = max(ans, min(a[j] + x, b[j] + y));
            }
            for (int j = l_blk + 1; j <= r_blk - 1; ++j)
            {
                clothes tmp = (clothes){0, 0, y - x};
                int idx = lower_bound(blk_cs[j].begin(), blk_cs[j].end(), tmp) - blk_cs[j].begin() + l[j] - 1;
                if (idx >= l[j])
                    ans = max(ans, pre_mx_a[idx] + x);
                if (idx < r[j])
                    ans = max(ans, suf_mx_b[idx + 1] + y);
            }
            for (int j = l[r_blk]; j <= R; ++j)
            {
                ans = max(ans, min(a[j] + x, b[j] + y));
            }
        }
        printf("%lld\n", ans);
        lst_ans = ans;
    }
    for (int i = 0; i <= blk_idx; ++i)
        blk_cs[i].clear();
    for (int i = 0; i <= n; ++i)
    {
        a[i] = b[i] = blk[i] = l[i] = r[i] = pre_mx_a[i] = suf_mx_b[i] = 0;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}