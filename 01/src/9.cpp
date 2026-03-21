#include <bits/stdc++.h>

using namespace std;
const int N = 205, K = 505, INF = 2e9;

struct state
{
    int x, y, cnt;
};
int x[K], y[K];
int ans[2 * N][2 * N];
int bfs(int k)
{
    for (int i = -200; i <= 200; ++i)
    {
        for (int j = -200; j <= 200; ++j)
        {
            ans[i + N][j + N] = INF;
        }
    }
    queue<state> q;
    q.push((state){0, 0, 0});
    while (!q.empty())
    {
        auto s = q.front();
        q.pop();
        for (int i = 1; i <= k; ++i)
        {
            auto nxt = s;
            nxt.x += x[i];
            nxt.y += y[i];
            ++nxt.cnt;
            if (nxt.x < -200 || nxt.x > 200 || nxt.y < -200 || nxt.y > 200)
            {
                continue;
            }
            if (nxt.cnt < ans[nxt.x + N][nxt.y + N])
            {
                ans[nxt.x + N][nxt.y + N] = nxt.cnt;
                if (nxt.x == 0 && nxt.y == 0)
                {
                    break;
                }
                q.push(nxt);
            }
        }
        if (ans[N][N] != INF)
        {
            break;
        }
    }
    return ans[N][N];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i)
        {
            cin >> x[i] >> y[i];
        }
        int res = bfs(k);
        if (res == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << res << '\n';
        }
    }
    return 0;
}