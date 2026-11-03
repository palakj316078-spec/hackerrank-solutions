// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-maximum-swap/problem?isFullScreen=true
// Problem     Greedy Algorithm - Maximum Swap
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:43 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    cin >> num;

    int last[10];

    for (int i = 0; i < 10; i++)
        last[i] = -1;

    for (int i = 0; i < num.length(); i++)
        last[num[i] - '0'] = i;

    for (int i = 0; i < num.length(); i++)
    {
        int digit = num[i] - '0';

        for (int d = 9; d > digit; d--)
        {
            if (last[d] > i)
            {
                char temp = num[i];
                num[i] = num[last[d]];
                num[last[d]] = temp;

                cout << num;
                return 0;
            }
        }
    }

    cout << num;

    return 0;
}
