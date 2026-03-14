#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int t = 1; t <= 100000; t++)
    {
        system("./gen > input.txt");

        system("./std < input.txt > out1.txt");
        system("./brute < input.txt > out2.txt");

        if (system("diff out1.txt out2.txt"))
        {
            cout << "Wrong Answer on test " << t << "\n";
            return 0;
        }

        cout << "Test " << t << " Passed\n";
    }
}
