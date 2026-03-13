#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = 1;
        if(n == 4) {
            printf("1\n");
            continue;
        }
        if(n == 6 || n == 8) {
            printf("2\n");
            continue;
        }
        for(int i = 3; i * i <= n; ++i) {
            if(n % i == 0){
                ans = n / i;
                break;
            } 
        }
        if(ans == 1 && n % 2 == 0) {
            ans = 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
