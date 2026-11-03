// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/dynamic-programming-word-search-in-a-character-grid/problem?isFullScreen=true
// Problem     Backtracking - Word Search in a Character Grid
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:07 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m, n;
vector<vector<char>> board;
string word;

bool search(int r, int c, int index)
{
    if (index == word.length())
        return true;

    if (r < 0 || r >= m || c < 0 || c >= n)
        return false;

    if (board[r][c] != word[index])
        return false;

    char temp = board[r][c];
    board[r][c] = '#';

    if (search(r + 1, c, index + 1) ||
        search(r - 1, c, index + 1) ||
        search(r, c + 1, index + 1) ||
        search(r, c - 1, index + 1))
    {
        return true;
    }

    board[r][c] = temp;

    return false;
}

int main()
{
    cin >> m >> n;

    board.resize(m, vector<char>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    cin >> word;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (search(i, j, 0))
            {
                cout << "true";
                return 0;
            }
        }
    }

    cout << "false";

    return 0;
}
