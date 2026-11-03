// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-n-queens-ii/problem?isFullScreen=true
// Problem     Backtracking-N-Queens II
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:08 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int n;
int board[10];
int countSolutions = 0;

bool safe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col)
            return false;

        if (abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

void solve(int row)
{
    if (row == n)
    {
        countSolutions++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (safe(row, col))
        {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    cin >> n;

    solve(0);

    cout << countSolutions;

    return 0;
}
