// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-shortest-unsorted-continuous-subarray/problem?isFullScreen=true
// Problem     Greedy Algorithm - Shortest Unsorted Continuous Subarray
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:05 a.m.
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

    int left = -1;
    int right = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            left = i;
            break;
        }
    }

    if (left == -1)
    {
        cout << 0;
        return 0;
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] > nums[i])
        {
            right = i;
            break;
        }
    }

    int minValue = nums[left];
    int maxValue = nums[left];

    for (int i = left; i <= right; i++)
    {
        minValue = min(minValue, nums[i]);
        maxValue = max(maxValue, nums[i]);
    }

    while (left > 0 && nums[left - 1] > minValue)
        left--;

    while (right < n - 1 && nums[right + 1] < maxValue)
        right++;

    cout << right - left + 1;

    return 0;
}
