// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-gas-station/problem?isFullScreen=true
// Problem     Greedy Algorithm - Gas Station
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:01 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int gas[100000];
    int cost[100000];

    for (int i = 0; i < n; i++)
        cin >> gas[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    int total = 0;
    int current = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        int diff = gas[i] - cost[i];

        total += diff;
        current += diff;

        if (current < 0)
        {
            start = i + 1;
            current = 0;
        }
    }

    if (total >= 0)
        cout << start;
    else
        cout << -1;

    return 0;
}
