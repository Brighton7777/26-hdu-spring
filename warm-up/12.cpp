#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int a[N];
int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        printf("%d\n", a[n] - a[1] + 1);
    }
    return 0;
}
