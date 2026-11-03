// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-split-array-into-consecutive-subsequences/problem?isFullScreen=true
// Problem     Greedy Algorithm - Split Array into Consecutive Subsequences
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:44 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    unordered_map<int, int> freq;
    unordered_map<int, int> need;

    for (int x : nums)
        freq[x]++;

    for (int x : nums)
    {
        if (freq[x] == 0)
            continue;

        if (need[x] > 0)
        {
            freq[x]--;
            need[x]--;
            need[x + 1]++;
        }
        else
        {
            if (freq[x + 1] > 0 && freq[x + 2] > 0)
            {
                freq[x]--;
                freq[x + 1]--;
                freq[x + 2]--;

                need[x + 3]++;
            }
            else
            {
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";

    return 0;
}
