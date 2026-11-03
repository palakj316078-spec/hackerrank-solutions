// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/number-of-longest-increasing-subsequences-dynamic-programming/problem?isFullScreen=true
// Problem     Number of Longest Increasing Subsequences - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:40 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> len(n, 1);
    vector<int> count(n, 1);

    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                if (len[j] + 1 > len[i])
                {
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
                else if (len[j] + 1 == len[i])
                {
                    count[i] += count[j];
                }
            }
        }

        maxLen = max(maxLen, len[i]);
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (len[i] == maxLen)
            answer += count[i];
    }

    cout << answer;

    return 0;
}
