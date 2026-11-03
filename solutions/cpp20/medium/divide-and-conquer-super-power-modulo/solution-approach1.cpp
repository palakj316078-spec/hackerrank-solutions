// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-super-power-modulo/problem?isFullScreen=true
// Problem     Divide and Conquer - Super Power Modulo
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:01 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int powerMod(int a, int b)
{
    int result = 1;
    a %= 1337;

    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % 1337;

        a = (a * a) % 1337;
        b /= 2;
    }

    return result;
}

int main()
{
    int a, n;
    cin >> a >> n;

    int b[2000];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int result = 1;
    a %= 1337;

    for (int i = 0; i < n; i++)
    {
        result = powerMod(result, 10);
        result = (result * powerMod(a, b[i])) % 1337;
    }

    cout << result;

    return 0;
}
