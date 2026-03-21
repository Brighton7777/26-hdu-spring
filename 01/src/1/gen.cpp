#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));

    int t = 5; // 单组方便对拍
    cout << t << "\n";

    while (t--)
    {
        int n = 100000; // 小数据（暴力用）
        cout << n << "\n";

        for (int i = 1; i <= n; ++i)
        {
            cout << (rand() % 10) * 1 + 2 << " ";
        }
        cout << "\n";
    }
    return 0;
}