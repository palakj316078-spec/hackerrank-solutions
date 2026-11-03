// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/partition-equal-subset-sum-dynamic-programming/problem?isFullScreen=true
// Problem     Partition Equal Subset Sum - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:37 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        total += nums[i];
    }

    if (total % 2 != 0)
    {
        cout << "false";
        return 0;
    }

    int target = total / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    if (dp[target])
        cout << "true";
    else
        cout << "false";

    return 0;
}
