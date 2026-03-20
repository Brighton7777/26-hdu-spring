#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
bool vis[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n >= k)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i <= k; ++i)
        {
            vis[i] = false;
        }
        int idx = 1, sum = 0;
        vis[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            while (vis[(sum + idx) % k] == true)
            {
                ++idx;
            }
            sum += idx;
            sum %= k;
            vis[sum] = true;
            printf("%d ", idx);
            ++idx;
        }
        printf("\n");
    }
    return 0;
}