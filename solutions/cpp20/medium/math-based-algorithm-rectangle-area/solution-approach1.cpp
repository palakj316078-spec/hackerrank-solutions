// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-rectangle-area/problem?isFullScreen=true
// Problem     Math Based Algorithm - Rectangle Area
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:18 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);

    int overlapWidth = max(0, min(ax2, bx2) - max(ax1, bx1));
    int overlapHeight = max(0, min(ay2, by2) - max(ay1, by1));

    int overlapArea = overlapWidth * overlapHeight;

    int totalArea = area1 + area2 - overlapArea;

    cout << totalArea;

    return 0;
}
