// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-minimum-deletions-to-make-array-divisible/problem?isFullScreen=true
// Problem     Math Based Algorithm - Minimum Deletions to Make Array Divisible
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:23 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    long long g;
    cin >> g;

    for (int i = 1; i < m; i++)
    {
        long long x;
        cin >> x;
        g = gcd(g, x);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (g % nums[i] == 0)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
