#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<vector<int>> plans(30);
void preprocess()
{
    // 1 2 3 4 6 9
    plans[0] = {9};
    plans[1] = {7, 1};
    plans[2] = {6, 0, 1};
    plans[3] = {5, 2};
    plans[4] = {5, 0, 0, 1};
    plans[5] = {4, 1, 1, 0};
    plans[6] = {3, 3};
    plans[7] = {3, 0, 2};
    plans[8] = {3, 1, 0, 1};
    plans[9] = {3, 0, 0, 0, 1};
    plans[10] = {2, 2, 1};
    plans[11] = {2, 0, 1, 1};
    plans[12] = {1, 1, 2};
    plans[13] = {1, 4};
    plans[14] = {1, 2, 0, 1};
    plans[15] = {1, 1, 0, 0, 1};
    plans[16] = {0, 0, 3};
    plans[17] = {0, 3, 1};
    plans[18] = {0, 1, 1, 1};
    plans[19] = {0, 0, 1, 0, 1};
    plans[20] = {0, 0, 0, 0, 0, 1};
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> vs(6, vector<ll>());
    for (int i = 1; i <= n; ++i)
    {
        ll a, b, v;
        cin >> a >> b >> v;
        int type = a * b;
        if (type <= 4)
        {
            vs[type - 1].push_back(v);
        }
        else if (type == 6)
        {
            vs[4].push_back(v);
        }
        else if (type == 9)
        {
            vs[5].push_back(v);
        }
    }
    for (int i = 0; i < 6; ++i)
    {
        sort(vs[i].begin(), vs[i].end());
        reverse(vs[i].begin(), vs[i].end());
        for (int j = 1; j < vs[i].size(); ++j)
        {
            // cout << vs[i][j] << " \n"[j == vs[i].size() - 1];
            vs[i][j] += vs[i][j - 1];
        }
    }
    ll ans = 0;
    for (int i = 0; i < 21; ++i)
    {
        ll res = 0;
        for (int j = 0; j < plans[i].size(); ++j)
        {
            if (vs[j].size() == 0 || plans[i][j] == 0)
            {
                continue;
            }
            if (plans[i][j] > vs[j].size())
            {
                res += vs[j][vs[j].size() - 1];
            }
            else
            {
                res += vs[j][plans[i][j] - 1];
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}