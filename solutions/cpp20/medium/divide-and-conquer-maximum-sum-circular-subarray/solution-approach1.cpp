// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-maximum-sum-circular-subarray/problem?isFullScreen=true
// Problem     Divide and Conquer - Maximum Sum Circular Subarray
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:14 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[30000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int total = 0;

    int currentMax = arr[0];
    int maxSum = arr[0];

    int currentMin = arr[0];
    int minSum = arr[0];

    for (int i = 0; i < n; i++)
    {
        total += arr[i];

        if (i > 0)
        {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSum = max(maxSum, currentMax);

            currentMin = min(arr[i], currentMin + arr[i]);
            minSum = min(minSum, currentMin);
        }
    }

    if (maxSum < 0)
        cout << maxSum;
    else
        cout << max(maxSum, total - minSum);

    return 0;
}
