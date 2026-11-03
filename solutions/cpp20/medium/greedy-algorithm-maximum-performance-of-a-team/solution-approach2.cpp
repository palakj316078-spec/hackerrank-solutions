// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-maximum-performance-of-a-team/problem?isFullScreen=true
// Problem     Greedy Algorithm - Maximum Performance of a Team
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:03 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> speed(n);
    vector<long long> efficiency(n);

    for (int i = 0; i < n; i++)
        cin >> speed[i];

    for (int i = 0; i < n; i++)
        cin >> efficiency[i];

    vector<pair<long long, long long>> engineers;

    for (int i = 0; i < n; i++)
        engineers.push_back({efficiency[i], speed[i]});

    sort(engineers.rbegin(), engineers.rend());

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < n; i++)
    {
        long long e = engineers[i].first;
        long long s = engineers[i].second;

        pq.push(s);
        sum += s;

        if (pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }

        answer = max(answer, sum * e);
    }

    cout << answer % 1000000007;

    return 0;
}
