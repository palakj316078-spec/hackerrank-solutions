// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-maximum-subarray-1/problem?isFullScreen=true
// Problem     Divide and Conquer - Maximum Subarray
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:00 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum;

    return 0;
}
