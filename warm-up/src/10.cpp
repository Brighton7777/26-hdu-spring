#include <bits/stdc++.h>

#define position pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 405;
int t[N][N];
struct teleport
{
    int p, q, w;
};
struct state
{
    position p;
    int m; // money
    bool operator<(const state &x) const
    {
        return m < x.m;
    }
};
vector<teleport> to[N][N];
int mov[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[N][N];
bool bfs(int n, int m, int time, int money)
{
    priority_queue<state> pq;
    pq.push((state){position(1, 1), money});
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            vis[i][j] = -1;
    }
    while (!pq.empty())
    {
        auto [p, mn] = pq.top();
        pq.pop();
        if (mn <= vis[p.x][p.y])
        {
            continue;
        }
        vis[p.x][p.y] = mn;
        for (int i = 0; i < 4; ++i)
        {
            position np = position{p.x + mov[i][0], p.y + mov[i][1]};
            if (np.x < 1 || np.x > n || np.y < 1 || np.y > m)
            {
                continue;
            }
            if (time >= t[np.x][np.y] && mn > vis[np.x][np.y])
            {
                if (np.x == n && np.y == m) // arrive at destination
                {
                    return true;
                }
                pq.push((state){np, mn});
            }
        }
        for (auto tp : to[p.x][p.y])
        {
            auto [nx, ny, w] = tp;
            if (mn >= w && time >= t[nx][ny] && mn - w > vis[nx][ny])
            {
                position np = position{nx, ny};
                if (np.x == n && np.y == m) // arrive at destination
                {
                    return true;
                }
                pq.push((state){np, mn - w});
            }
        }
    }
    return false;
}
int binary_search(int n, int m, int money)
{
    int l = 0, r = 1e9 + 5;
    while (l < r - 1)
    {
        // printf("%d\n", r);
        int mid = (l + r) >> 1;
        if (bfs(n, m, mid, money))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    while (bfs(n, m, r - 1, money) && r > 0)
        --r;
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, money, k;
        cin >> n >> m >> money >> k;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> t[i][j];
            }
        for (int i = 1; i <= k; ++i)
        {
            int x, y, p, q, w;
            cin >> x >> y >> p >> q >> w;
            to[x][y].push_back((teleport){p, q, w});
        }
        printf("%d\n", binary_search(n, m, money));
        // printf("%d\n", bfs(n, m, 5, money));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                t[i][j] = 0;
                to[i][j].clear();
            }
        }
    }
}
/*
2
3 3 0 0
0 1 2
3 4 5
6 7 0
4 4 100 3
0 10 1 10
10 1 10 1
1 10 1 1
1 1 5 0
1 1 1 3 10
1 3 4 1 10
4 1 3 3 100

*/