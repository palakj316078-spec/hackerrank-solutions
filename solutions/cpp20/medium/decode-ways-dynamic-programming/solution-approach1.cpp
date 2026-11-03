// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/decode-ways-dynamic-programming/problem?isFullScreen=true
// Problem     Decode Ways - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:42 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    if (s[0] == '0')
    {
        cout << 0;
        return 0;
    }

    int dp[101] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] >= '1' && s[i - 1] <= '9')
            dp[i] += dp[i - 1];

        int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (num >= 10 && num <= 26)
            dp[i] += dp[i - 2];
    }

    cout << dp[n];

    return 0;
}
