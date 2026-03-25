#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 500005, MAX_A = 1e6 + 5, MAX_P = 80000;
ll a[N], hs[N];
ll p[MAX_P], prime_cnt, spf[MAX_A];
ull r[MAX_P];
unordered_map<ll, ull> p_r;
mt19937_64 gen(114514);
void preprocess()
{
    vector<bool> is_prime(MAX_A + 1, true);
    for (int i = 2; i < MAX_A; ++i)
    {
        if (is_prime[i] == true)
        {
            p[++prime_cnt] = i;
            r[prime_cnt] = (ull)gen();
            p_r[i] = r[prime_cnt];
        }
        for (int j = 1; j <= prime_cnt; ++j)
        {
            if (i * p[j] > MAX_A)
            {
                break;
            }
            is_prime[i * p[j]] = false;
            spf[i * p[j]] = p[j];
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    return;
}
ull get_hash(ll num)
{
    ull h = 0;
    while (spf[num] != 0)
    {
        h ^= p_r[spf[num]];
        num /= spf[num];
    }
    if (num != 1)
    {
        h ^= p_r[num];
    }
    return h;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    unordered_map<ull, int> hs_cnt;
    ++hs_cnt[0];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        hs[i] = hs[i - 1] ^ get_hash(a[i]);
        ++hs_cnt[hs[i]];
    }
    ll ans = 0;
    ull hx = get_hash(x);
    for (int i = 0; i <= n; ++i)
    {
        ull target = hx ^ hs[i];
        ans += hs_cnt[target];
    }
    cout << ans / 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    // cout << prime_cnt << '\n';
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}