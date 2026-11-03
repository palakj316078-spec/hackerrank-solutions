// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/divide-and-conquer-k-closest-points-to-origin/problem?isFullScreen=true
// Problem     Divide and Conquer - K Closest Points To Origin
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:03 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
    int dist;
};

int main()
{
    int n, k;
    cin >> n >> k;

    Point p[10000];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
        p[i].dist = p[i].x * p[i].x + p[i].y * p[i].y;
    }

    for (int i = 0; i < k; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (p[j].dist < p[minIndex].dist)
                minIndex = j;
        }

        Point temp = p[i];
        p[i] = p[minIndex];
        p[minIndex] = temp;
    }

    for (int i = 0; i < k; i++)
        cout << p[i].x << " " << p[i].y << endl;

    return 0;
}
