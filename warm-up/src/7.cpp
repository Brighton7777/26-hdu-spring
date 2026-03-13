#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N], sum0[N], sum1[N], x[N], y[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), sum0[i] = sum1[i] = 0;
        for(int i = 0; i <= n + 1; ++i)
            x[i] = y[i] = -2e9;
        int mn = 0;
        for(int i = 1; i <= n; ++i) {
            sum0[i] = sum0[i - 1] + a[i];
            x[i] = max(x[i - 1], sum0[i] - mn);
            mn = min(mn, sum0[i]);
        }
        mn = 0;
        for(int i = n; i >= 1; --i) {
            sum1[i] = sum1[i + 1] + a[i];
            y[i] = max(y[i + 1], sum1[i] - mn);
            mn = min(mn, sum1[i]);
        }
        int ans = -2e9;
        for(int i = 3; i <= n - 2; ++i) {
            ans = max(ans, x[i - 2] + a[i] + y[i + 2]);
        }
        printf("%d\n", ans);
    }    
    return 0;
}
