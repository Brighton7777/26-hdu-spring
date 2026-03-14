#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

int rnd(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = rnd(1, 5); // 小数据方便对拍
    cout << T << "\n";

    while (T--)
    {
        int n = rnd(1, 5);
        int q = rnd(1, 5);

        cout << n << " " << q << "\n";

        for (int i = 1; i <= n; i++)
        {
            int a = rnd(0, 20);
            int b = rnd(0, 20);
            cout << a << " " << b << "\n";
        }

        for (int i = 1; i <= q; i++)
        {
            int l = rnd(1, n);
            int r = rnd(1, n);
            if (l > r)
                swap(l, r);

            int X = rnd(0, 20);
            int Y = rnd(0, 20);

            cout << l << " " << r << " " << X << " " << Y << "\n";
        }
    }
}
