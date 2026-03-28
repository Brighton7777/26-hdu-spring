#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 500005;
const ll INF = 1e18;
void solve()
{
    ll x, k;
    cin >> x >> k;
    vector<int> ans;
    ans.clear();
    if (k <= x)
    {
        for (int i = 1; i <= k; ++i)
        {
            cout << "1 ";
        }
        cout << '\n';
        return;
    }
    // if (x > 60)
    // {
    //     for (int i = 1; i <= k; ++i)
    //     {
    //         cout << "1 ";
    //     }
    //     cout << '\n';
    //     return;
    // }
    for (int i = x; i >= 1; --i)
    {
        ll tmp = i;
        ll lim = (1ll << (i - 1));
        while (k > lim && tmp > 1)
        {
            --tmp;
            lim += (1ll << (tmp - 1));
        }
        ans.push_back((i - tmp + 1));
        i = tmp;
        k -= lim - (1ll << (tmp - 1));
        --k;
        if (k <= 0)
        {
            break;
        }
    }
    for (auto x : ans)
    {
        cout << x << ' ';
    }
    cout << '\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 20;
    cout << (1 << n) - 1 << '\n';
    for (int i = 1; i <= (1 << n) - 1; ++i)
    {
        cout << n << ' ' << i << '\n';
    }
    return 0;
}
/*
3
60 100000000000000000
60 90000000000000000
60 90000000000000000
*/