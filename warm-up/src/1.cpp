#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 3; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                ans = n / i;
                break;
            }
        }
        if (n % 2 == 0 && n / 2 >= 3)
        {
            ans = max(ans, 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
