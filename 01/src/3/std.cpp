#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int n;
string S, T;
int palS[N + 10], palT[N + 10];
int sumS[N + 10], sumT[N + 10];
int lcp[N + 10][N + 10];

void work()
{
    cin >> S >> T;
    n = S.size();
    reverse(T.begin(), T.end());
    S = " " + S + " ", T = " " + T + " ";
    for (int i = 1; i <= n; ++i)
        palS[i] = palT[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = i, r = i;
        while (1 <= l && r <= n && S[l] == S[r])
            ++palS[l--], ++r;
        l = i, r = i + 1;
        while (1 <= l && r <= n && S[l] == S[r])
            ++palS[l--], ++r;
        l = i, r = i;
        while (1 <= l && r <= n && T[l] == T[r])
            ++palT[l--], ++r;
        l = i, r = i + 1;
        while (1 <= l && r <= n && T[l] == T[r])
            ++palT[l--], ++r;
    }
    sumS[0] = sumT[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        sumS[i] = sumS[i - 1] + palS[i], sumT[i] = sumT[i - 1] + palT[i];
    }
    sumS[n + 1] = sumS[n], sumT[n + 1] = sumT[n];
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j <= n + 1; ++j)
        {
            lcp[i][j] = 0;
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = n; j >= 1; --j)
        {
            if (S[i] == T[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
        }
    }
    long long ans = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (!lcp[i][j])
                continue;
            ans += lcp[i][j] + (sumS[i + lcp[i][j]] - sumS[i]) + (sumT[j + lcp[i][j]] - sumT[j]);
        }
    }
    cout << ans << '\n';
}

int main()
{
    int T;
    cin >> T;
    for (; T--;)
        work();
    return 0;
}