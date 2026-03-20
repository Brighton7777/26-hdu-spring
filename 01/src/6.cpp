#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
struct col
{
    long long s, d;
    bool operator<(const col &x) const
    {
        return s < x.s;
    }
} cs[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> cs[i].s >> cs[i].d;
        }
        sort(cs + 1, cs + 1 + n);
        long long tm = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (tm <= cs[i].s)
            {
                tm = cs[i].s;
            }
            tm += cs[i].d;
        }
        cout << tm << '\n';
    }
    return 0;
}