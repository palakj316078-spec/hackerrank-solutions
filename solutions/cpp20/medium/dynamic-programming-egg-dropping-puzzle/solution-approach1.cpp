// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-egg-dropping-puzzle/problem?isFullScreen=true
// Problem     Dynamic Programming - Egg Dropping Puzzle
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:33 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;

    vector<long long> dp(k + 1, 0);

    int moves = 0;

    while (dp[k] < n)
    {
        moves++;

        for (int eggs = k; eggs >= 1; eggs--)
        {
            dp[eggs] = dp[eggs] + dp[eggs - 1] + 1;
        }
    }

    cout << moves;

    return 0;
}
