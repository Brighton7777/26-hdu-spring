#include <bits/stdc++.h>

using namespace std;

const int N = 400005;
int a[N], tmp[2 * N], op[N], x[N], y[N], ans[N * 2];
vector<int> pos[2 * N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i], tmp[i] = a[i];
        int tmp_idx = n;
        cin >> m;
        for(int i = 1; i <= m; ++i)
            op[i] = x[i] = y[i] = 0;  
        for(int i = 1; i <= m; ++i){
            cin >> op[i] >> x[i];
            tmp[++tmp_idx] = x[i];
            if(op[i] == 1)
                cin >> y[i], tmp[++tmp_idx] = y[i];
        }
        sort(tmp + 1, tmp + 1 + tmp_idx);
        unordered_map<int, int> id, re;
        int idx = 0;
        for(int i = 1; i <= tmp_idx; ++i) {
            if(tmp[i] != tmp[i - 1])
                id[tmp[i]] = ++idx, re[idx] = tmp[i];
        }
        for(int i = 1; i <= idx; ++i)
            pos[i].clear();
        for(int i = 1; i <= n; ++i) {
            pos[id[a[i]]].push_back(i);
        }
        for(int i = 1; i <= m; ++i) {
            if(op[i] == 1) {
                vector<int> tmpx = pos[id[x[i]]], tmpy = pos[id[y[i]]];
                pos[id[x[i]]].clear();
                if(tmpx.size() > tmpy.size())
                    swap(tmpx, tmpy);
                tmpy.insert(tmpy.end(), tmpx.begin(), tmpx.end());
                pos[id[y[i]]] = tmpy;
            }
            else if(op[i] == 2) {
                pos[id[x[i]]].push_back(n + i);
            }
            else {
                pos[id[x[i]]].clear();
            }
        }
        for(int i = 1; i <= n + m; ++i) {
            ans[i] = 0;
        }
        for(int i = 1; i <= idx; ++i) {
            for(int j = 0; j < pos[i].size(); ++j)
                ans[pos[i][j]] = re[i];
        } 
        for(int i = 1; i <= n + m; ++i) {
            if(ans[i] != 0) 
                cout << ans[i] << ' ';
        }
        cout << '\n';
        for(int i = 1; i <= idx; ++i)
            pos[i].clear();
        for(int i = 1; i <= n + 2 * m; ++i)
            tmp[i] = 0;
    }
    
    return 0;
}
