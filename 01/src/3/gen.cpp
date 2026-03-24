#include <bits/stdc++.h>
using namespace std;

mt19937 rng(time(0));

int rand_int(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(rng);
}

string gen_str(int n)
{
    string s;
    for (int i = 0; i < n; i++)
        s += char('a' + rand_int(0, 2)); // 小字母集更容易卡
    return s;
}

int main()
{
    int T = 3;
    cout << T << "\n";
    while (T--)
    {
        int n = rand_int(1, 8); // 小范围对拍

        string s = gen_str(n);
        string t = gen_str(n);

        cout << s << "\n";
        cout << t << "\n";
    }
    return 0;
}