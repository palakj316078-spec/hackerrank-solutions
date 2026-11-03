// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-minimum-number-of-arrows-to-burst-balloons/problem?isFullScreen=true
// Problem     Greedy Algorithm - Minimum Number of Arrows to Burst Balloons
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:47 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<long long, long long>> balloons(n);

    for (int i = 0; i < n; i++)
        cin >> balloons[i].first >> balloons[i].second;

    sort(balloons.begin(), balloons.end());

    int arrows = 1;
    long long arrow = balloons[0].second;

    for (int i = 1; i < n; i++)
    {
        if (balloons[i].first > arrow)
        {
            arrows++;
            arrow = balloons[i].second;
        }
        else
        {
            arrow = min(arrow, balloons[i].second);
        }
    }

    cout << arrows;

    return 0;
}
