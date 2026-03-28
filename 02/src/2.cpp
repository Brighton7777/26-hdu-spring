#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 500005;
const int INF = 1e9 + 7;
struct node
{
    ll x, y, d;
};
vector<bool> vis;
vector<vector<int>> es;
vector<int> match;
bool dfs(int u)
{
    // cout << u << ' ';
    for (auto v : es[u])
    {
        if (vis[v])
            continue;
        vis[v] = true;
        if (match[v] == -1 || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), d(n);
    vis.resize(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> d[i];
    }
    vector<ll> xs = x, ys = y;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    vector<vector<ll>> mx(2), my(2);
    mx[0].resize(n + 1, INF);
    mx[1].resize(n + 1, 0);
    my[0].resize(n + 1, INF);
    my[1].resize(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
        y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin() + 1;
        if (d[i] == 1 || d[i] == 3)
        {
            mx[0][y[i]] = min(mx[0][y[i]], x[i]);
            mx[1][y[i]] = max(mx[1][y[i]], x[i]);
        }
        else
        {
            my[0][x[i]] = min(my[0][x[i]], y[i]);
            my[1][x[i]] = max(my[1][x[i]], y[i]);
        }
    }
    vector<node> ns;
    for (int i = 0; i < n; ++i)
    {
        if (d[i] == 0 && y[i] == my[1][x[i]])
        {
            ns.push_back((node){x[i], y[i], d[i]});
        }
        if (d[i] == 1 && x[i] == mx[1][y[i]])
        {
            ns.push_back((node){x[i], y[i], d[i]});
        }
        if (d[i] == 2 && y[i] == my[0][x[i]])
        {
            ns.push_back((node){x[i], y[i], d[i]});
        }
        else if (d[i] == 3 && x[i] == mx[0][y[i]])
        {
            ns.push_back((node){x[i], y[i], d[i]});
        }
    }
    es.resize(n + 1);
    int e_cnt = 0;
    match.resize(n + 1);
    for (int i = 0; i < n; ++i)
    {
        match[i] = -1;
        es[i].clear();
    }
    for (int i = 0; i < ns.size(); ++i)
    {
        for (int j = i + 1; j < ns.size(); ++j)
        {
            if (ns[i].d == 0 && ns[i].y <= ns[j].y && ((ns[j].d == 3 && ns[j].x >= ns[i].x) || (ns[j].d == 1 && ns[j].x <= ns[i].x)))
            {
                ++e_cnt;
                es[i].push_back(j);
            }
            else if (ns[i].d == 1 && ns[i].x <= ns[j].x && ((ns[j].d == 0 && ns[j].y <= ns[i].y) || (ns[j].d == 2 && ns[j].y >= ns[i].y)))
            {
                ++e_cnt;
                es[j].push_back(i);
            }
            else if (ns[i].d == 2 && ns[i].y >= ns[j].y && ((ns[j].d == 3 && ns[j].x >= ns[i].x) || (ns[j].d == 1 && ns[j].x <= ns[i].x)))
            {
                ++e_cnt;
                es[i].push_back(j);
            }
            else if (ns[i].d == 3 && ns[i].x >= ns[j].x && ((ns[j].d == 0 && ns[j].y <= ns[i].y) || (ns[j].d == 2 && ns[j].y >= ns[i].y)))
            {
                ++e_cnt;
                es[j].push_back(i);
            }
        }
    }
    int res = 0;
    vis.resize(n + 1, 0);
    for (int i = 0; i < ns.size(); ++i)
    {
        for (int j = 0; j < ns.size(); ++j)
        {
            vis[j] = 0;
        }
        if (dfs(i))
            ++res;
    }
    cout << ns.size() - res << '\n';
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