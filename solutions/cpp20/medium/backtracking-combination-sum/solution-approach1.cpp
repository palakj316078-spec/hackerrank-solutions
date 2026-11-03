// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-combination-sum/problem?isFullScreen=true
// Problem     Backtracking-combination sum
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:10 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> candidates;
vector<int> current;
vector<vector<int>> result;

void solve(int index, int target)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if (candidates[i] > target)
            break;

        current.push_back(candidates[i]);

        solve(i, target - candidates[i]);

        current.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;

    candidates.resize(n);

    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    int target;
    cin >> target;

    sort(candidates.begin(), candidates.end());

    solve(0, target);

    if (result.empty())
    {
        cout << -1;
        return 0;
    }

    for (vector<int> combination : result)
    {
        for (int x : combination)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
