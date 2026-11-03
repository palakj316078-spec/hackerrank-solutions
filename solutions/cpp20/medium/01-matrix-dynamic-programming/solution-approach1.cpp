// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/01-matrix-dynamic-programming/problem?isFullScreen=true
// Problem     01 Matrix - Dynamic Programming
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:39 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> dist(m, vector<int>(n, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];

            if (matrix[i][j] == 0)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                dist[nr][nc] == -1)
            {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j];

            if (j < n - 1)
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
