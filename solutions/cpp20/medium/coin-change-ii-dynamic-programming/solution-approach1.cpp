// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/coin-change-ii-dynamic-programming/problem?isFullScreen=true
// Problem     Coin Change II - Dynamic Programming
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
    int amount, n;
    cin >> amount >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[amount];

    return 0;
}
