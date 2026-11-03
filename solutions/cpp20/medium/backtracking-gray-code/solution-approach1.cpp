// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-gray-code/problem?isFullScreen=true
// Problem     Backtracking-Gray Code
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:03 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int total = 1 << n;

    for (int i = 0; i < total; i++)
    {
        int gray = i ^ (i >> 1);

        cout << gray;

        if (i < total - 1)
            cout << " ";
    }

    return 0;
}
