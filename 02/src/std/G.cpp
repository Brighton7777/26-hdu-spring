#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1 << 19; // 足够大，覆盖前缀异或的可能值域
int cnt_even[MAX], cnt_odd[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] ^ x[i - 1];
        }
        ll even_count = 0, odd_count = 0;
        vector<int> used_even, used_odd;
        for (int i = 0; i <= n; i++) {
            if (i % 2 == 0) {
                even_count++;
                int v = pref[i];
                cnt_even[v]++;
                if (cnt_even[v] == 1) {
                    used_even.push_back(v);
                }
            } else {
                odd_count++;
                int v = pref[i];
                cnt_odd[v]++;
                if (cnt_odd[v] == 1) {
                    used_odd.push_back(v);
                }
            }
        }
        ll total_pairs = even_count * (even_count - 1) / 2 + odd_count * (odd_count - 1) / 2;
        ll same_pairs = 0;
        for (int v : used_even) {
            ll c = cnt_even[v];
            same_pairs += c * (c - 1) / 2;
        }
        for (int v : used_odd) {
            ll c = cnt_odd[v];
            same_pairs += c * (c - 1) / 2;
        }
        ll win_tora = total_pairs - same_pairs;
        ll total = (ll)n * (n + 1) / 2;
        cout << win_tora << " " << total - win_tora << "\n";
        // 重置计数数组
        for (int v : used_even) cnt_even[v] = 0;
        for (int v : used_odd) cnt_odd[v] = 0;
    }
    return 0;
}