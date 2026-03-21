#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    
    queue<int> q;
    q.push(1);
    parent[1] = -1; // root
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    vector<long long> S(n + 1, 0);
    vector<int> C(n + 1, 0);
    vector<long long> f(n + 1, 0);
    vector<long long> min_child_f(n + 1, 2e18);
    vector<bool> is_leaf(n + 1, true);

    for (int i = 1; i <= n; ++i) {
        S[i] = A[i];
        C[i] = 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        int u = order[i];
        
        long long avg = S[u] / C[u];
        if (is_leaf[u]) {
            f[u] = avg;
        } else {
            f[u] = min(avg, min_child_f[u]);
        }
        
        int p = parent[u];
        if (p != -1) {
            is_leaf[p] = false;
            S[p] += S[u];
            C[p] += C[u];
            if (f[u] < min_child_f[p]) {
                min_child_f[p] = f[u];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << f[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
