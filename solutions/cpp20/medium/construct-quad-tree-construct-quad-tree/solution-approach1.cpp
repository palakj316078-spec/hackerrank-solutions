// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/construct-quad-tree-construct-quad-tree/problem?isFullScreen=true
// Problem     Divide and Conquer - Construct Quad Tree
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:00 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int grid[64][64];

bool same(int r, int c, int size)
{
    int value = grid[r][c];

    for (int i = r; i < r + size; i++)
    {
        for (int j = c; j < c + size; j++)
        {
            if (grid[i][j] != value)
                return false;
        }
    }

    return true;
}

void quadTree(int r, int c, int size)
{
    if (same(r, c, size))
    {
        cout << "1 " << grid[r][c] << endl;
        return;
    }

    cout << "0 " << grid[r][c] << endl;

    int half = size / 2;

    quadTree(r, c, half);
    quadTree(r, c + half, half);
    quadTree(r + half, c, half);
    quadTree(r + half, c + half, half);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    quadTree(0, 0, n);

    return 0;
}
