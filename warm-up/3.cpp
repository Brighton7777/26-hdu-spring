#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int ans = 1;
        --n, --m;
        if(n > m)
            swap(n, m);
        ans += n;
        ans += (m - n) / 2 + (m - n) % 2;
        printf("%d\n", ans);
    }    
    return 0;
}
