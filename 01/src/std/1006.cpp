#include <bits/stdc++.h>
using namespace std;
int T, n;
long long res;
pair<int, int> lst[500005];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n; res = 0;
        for (int i = 0; i < n; i++)
            cin >> lst[i].first >> lst[i].second;
        sort(lst, lst + n);
        for (int i = 0; i < n; i++)
        {
            res = max(res, 1ll * lst[i].first);
            res += lst[i].second;
        }
        cout << res << "\n";
    }
    return 0;
}