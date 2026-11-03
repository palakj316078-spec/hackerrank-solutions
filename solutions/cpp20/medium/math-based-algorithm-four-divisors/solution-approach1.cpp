// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-four-divisors/problem?isFullScreen=true
// Problem     Math Based Algorithm - Four Divisors
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:15 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int count = 0;
        int sum = 0;

        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                int d1 = j;
                int d2 = x / j;

                if (d1 == d2)
                {
                    count++;
                    sum += d1;
                }
                else
                {
                    count += 2;
                    sum += d1 + d2;
                }
            }
        }

        if (count == 4)
            ans += sum;
    }

    cout << ans;

    return 0;
}
