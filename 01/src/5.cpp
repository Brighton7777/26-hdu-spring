#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e9;
ll qpow(ll a, ll b)
{
    ll base = a, res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= base;
            if (res >= N + 5)
            {
                return N + 5;
            }
        }
        base *= base;
        if (base >= N + 5)
        {
            base = N + 5;
        }
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll k, n;
        cin >> n >> k;
        ll l = 1, r = n + 1;
        while (l < r - 1)
        {
            ll mid = (l + r) >> 1;
            // printf("%lld %lld\n", l, r);
            ll res = qpow(mid, k);
            // printf("%lld, %lld\n", mid, res);
            if (res <= n)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        while (qpow(l + 1, k) <= n)
        {
            ++l;
        }
        printf("%lld\n", l);
    }
    return 0;
}
