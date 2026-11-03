// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/sorting-exam-scores-using-selection-sort/problem?isFullScreen=true
// Problem     Sorting: Sorting Exam Scores Using Selection Sort
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 07:54 a.m.
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

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
