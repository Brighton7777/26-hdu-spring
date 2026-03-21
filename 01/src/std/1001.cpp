#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

int n;
int a[maxn];
int L[maxn], R[maxn];
vector<pair<int, int>> sorted_vals; 

// 在区间 [l, r] 中查找数值 val 出现的次数
int count(int val, int l, int r) {
    auto it_start = lower_bound(sorted_vals.begin(), sorted_vals.end(), make_pair(val, -1));
    if (it_start == sorted_vals.end() || it_start->first != val) return 0;
    auto it_end = upper_bound(sorted_vals.begin(), sorted_vals.end(), make_pair(val, maxn));
    auto sub_l = lower_bound(it_start, it_end, make_pair(val, l));
    auto sub_r = lower_bound(it_start, it_end, make_pair(val, r + 1));
    
    return distance(sub_l, sub_r);
}

void solve() {
    sorted_vals.clear();
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sorted_vals.push_back({a[i], i});
    }

    sort(sorted_vals.begin(), sorted_vals.end());

    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        L[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        R[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    ll ans = 1ll * n * n;

    for (int p = 1; p <= n; ++p) {
        int l = L[p] + 1, r = R[p] - 1;

        // 计算必败情况：a_x + a_y = a[p] + 1
        // 如果 a[p] 是偶数，a[p]+1 是奇数，需要一奇一偶相加，必胜，无必败对。
        // 只有 a[p] 是奇数时才可能输
        if (a[p] % 2 != 0) {
            if (p - l < r - p) {
                for (int i = l; i <= p; ++i) {
                    int v = a[p] + 1 - a[i];
                    if (v >= 2) {
                        ans -= count(v, p, r) * 2;
                    }
                }
            } else {
                for (int i = p; i <= r; ++i) {
                    int v = a[p] + 1 - a[i];
                    if (v >= 2) {
                        ans -= count(v, l, p) * 2;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
