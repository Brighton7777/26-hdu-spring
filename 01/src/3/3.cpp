#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4005;
const int P = 131;
const ll M = 1e9 + 7;
int l[N], r[N];
void manacher(string s, bool isLeft = true)
{
    string t = "^";
    for (char c : s)
    {
        t.push_back('#');
        t.push_back(c);
    }
    t += "#$";

    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;
    for (int i = 1; i < n; ++i)
    {
        int mirror = 2 * center - i;
        if (i < right)
        {
            p[i] = min(right - i, p[mirror]);
        }
        while (t[i - p[i] - 1] == t[i + p[i] + 1])
        {
            ++p[i];
        }
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        if (isLeft)
        {
            ++l[i - p[i]];
            --l[i + 1];
        }
        else
        {
            ++r[i];
            --r[i + p[i] + 1];
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (isLeft)
        {
            l[i] += l[i - 1];
        }
        else
        {
            r[i] += r[i - 1];
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        if (isLeft)
        {
            l[i / 2 - 1] = l[i];
        }
        else
        {
            r[i / 2 - 1] = r[i];
        }
    }
}
vector<ll> hs, ht, hrt;
ll p[N];
void preprocess()
{
    p[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        p[i] = p[i - 1] * P % M;
    }
}
vector<ll> build_hash(string s)
{
    int n = s.size();
    vector<ll> h(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        h[i] = (h[i - 1] * P % M + (s[i - 1] - 'a')) % M;
    }
    return h;
}
ll get_hash(vector<ll> &h, int l, int r) // l, r is 0-index
{
    return (h[r + 1] - h[l] * p[r - l + 1] % M + M) % M;
}
bool check(int ls, int rs, int lrt, int rrt)
{
    if (get_hash(hs, ls, rs) == get_hash(hrt, lrt, rrt))
    {
        return true;
    }
    return false;
}
int find_len(const string &s, const string &t, int x, int y)
{
    if (s[x] != t[y])
    {
        return 0;
    }
    int l = 1, max_len = min((int)s.size() - x, y + 1);
    int r = max_len; // length
    int len_t = t.size();
    int rl = len_t - 1 - y;
    while (l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (check(x, x + mid - 1, rl, rl + mid - 1))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    while (l < max_len && check(x, x + l, rl, rl + l))
    {
        ++l;
    }
    return l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        string rt = t;
        reverse(rt.begin(), rt.end());
        hs = build_hash(s);
        ht = build_hash(t);
        hrt = build_hash(rt);
        // cout << s << ' ' << t << ' ' << rt << '\n';
        for (int i = 0; i < N; ++i)
        {
            l[i] = r[i] = 0;
        }
        manacher(s, true);
        manacher(t, false);
        int len_s = s.size(), len_t = t.size();
        // l, r is 0-index
        for (int i = 1; i < len_s; ++i)
        {
            l[i] += l[i - 1];
        }
        for (int i = len_s; i <= len_s + 5; ++i)
        {
            l[i] = l[i - 1];
        }
        for (int i = 1; i < len_t; ++i)
        {
            r[i] += r[i - 1];
        }
        long long ans = 0;
        l[len_s + 1] = l[len_s];
        for (int i = 0; i < len_s; ++i)
        {
            for (int j = 0; j < len_t; ++j)
            {
                int shared_len = find_len(s, t, i, j);
                if (shared_len == 0)
                {
                    continue;
                }
                long long res = l[i + shared_len] - l[i];
                if (j == 0)
                {
                    res += 0;
                }
                else if (j - shared_len - 1 < 0)
                {
                    res += r[j - 1];
                }
                else
                {
                    res += r[j - 1] - r[j - shared_len - 1];
                }
                ans += res + shared_len;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}