// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-increasing-triplet-subsequence/problem?isFullScreen=true
// Problem     Greedy Algorithm - Increasing Triplet Subsequence
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:59 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long first = LLONG_MAX;
    long long second = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        if (x <= first)
            first = x;
        else if (x <= second)
            second = x;
        else
        {
            cout << "true";
            return 0;
        }
    }

    cout << "false";

    return 0;
}
