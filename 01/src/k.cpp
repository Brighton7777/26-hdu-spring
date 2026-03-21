#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
const int N = 205, K = 505;
static std::mt19937 rng(114514);
struct state
{
    int x, y, cnt;
};
struct move
{
    int x, y;
} ms[K];
int vis[4 * N][4 * N];
auto start = steady_clock::now();
const double TIME_LIMIT = 0.45;
int bfs(int k)
{
    for (int i = -205; i <= 205; ++i)
    {
        for (int j = -205; j <= 205; ++j)
        {
            vis[i + 2 * N][j + 2 * N] = false;
        }
    }
    queue<state> q;
    q.push((state){0, 0, 0});
    vis[0][0] = true;
    while (!q.empty())
    {
        auto s = q.front();
        q.pop();
        for (int i = 1; i <= 2 * k; ++i)
        {
            if (s.x + ms[i].x < -205 || s.x + ms[i].x > 205 || s.y + ms[i].y < -205 || s.y + ms[i].y > 205)
            {
                continue;
            }
            auto nxt = s;
            nxt.x += ms[i].x;
            nxt.y += ms[i].y;
            ++nxt.cnt;
            if (vis[nxt.x + 2 * N][nxt.y + 2 * N] == false)
            {
                vis[nxt.x + 2 * N][nxt.y + 2 * N] = true;
                q.push(nxt);
            }
            if (vis[0 + 2 * N][1 + 2 * N] && vis[0 + 2 * N][-1 + 2 * N] && vis[-1 + 2 * N][0 + 2 * N] && vis[1 + 2 * N][0 + 2 * N])
            {
                return true;
            }
        }
        auto now = steady_clock::now();
        double elapsed = duration<double>(now - start).count();
        if (elapsed > TIME_LIMIT)
        {
            return false;
        }
    }
    if (vis[0 + 2 * N][1 + 2 * N] && vis[0 + 2 * N][-1 + 2 * N] && vis[-1 + 2 * N][0 + 2 * N] && vis[1 + 2 * N][0 + 2 * N])
    {
        return true;
    }
    else
    {
        return false;
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
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i)
        {
            cin >> ms[i].x >> ms[i].y;
            ms[i + k].x = -ms[i].x;
            ms[i + k].y = -ms[i].y;
        }
        auto now = steady_clock::now();
        double elapsed = duration<double>(now - start).count();
        if (elapsed > TIME_LIMIT)
        {
            printf("NO\n");
            continue;
        }
        shuffle(ms + 1, ms + 1 + 2 * k, rng);
        bool res = bfs(k);
        if (res == false)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}