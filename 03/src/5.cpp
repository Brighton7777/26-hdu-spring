#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> get_vec(ll val)
{
    vector<int> res(60, 0);
    for (int i = 0; i <= 59; ++i)
    {
        res[i] = val % 3;
        val /= 3;
    }
    return res;
}
void add_vec(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i <= 59; ++i)
    {
        a[i] = (a[i] + b[i]) % 3;
    }
    return;
}
bool check(vector<int> &a)
{
    for (int i = 0; i <= 59; ++i)
        if (a[i] != 0)
            return false;
    return true;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> vs(n);
    for (int i = 0; i < n; ++i)
    {
        ll val;
        cin >> val;
        vs[i] = get_vec(val);
    }
    vector<int> ps(60);
    vector<bool> vis(n, false);
    for (int i = 59; i >= 0; --i)
    {
        int pos = -1;
        for (int j = 0; j < n; ++j)
        {
            if (vis[j])
            {
                continue;
            }
            if (vs[j][i] != 0)
            {
                if (pos == -1)
                {
                    pos = j;
                }
                else
                {
                    add_vec(vs[j], vs[pos]);
                    if (vs[j][i] != 0)
                        add_vec(vs[j], vs[pos]);
                }
            }
        }
        ps[i] = pos;
        if (pos != -1)
        {
            vis[pos] = true;
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        ll val;
        cin >> val;
        vector<int> v = get_vec(val);
        bool failed = false;
        for (int j = 59; j >= 0; --j)
        {
            if (v[j] != 0)
            {
                // cout << j << ' ' << ps[j] << '\n';
                if (ps[j] == -1)
                {
                    failed = true;
                    break;
                }
                else
                {
                    add_vec(v, vs[ps[j]]);
                    if (v[j] != 0)
                        add_vec(v, vs[ps[j]]);
                }
            }
        }
        if (failed || (!check(v)))
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
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