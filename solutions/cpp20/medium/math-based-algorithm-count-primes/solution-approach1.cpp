// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-count-primes/problem?isFullScreen=true
// Problem     Math Based Algorithm - Count Primes 
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:21 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << 0;
        return 0;
    }

    vector<bool> prime(n, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
                prime[j] = false;
        }
    }

    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            count++;
    }

    cout << count;

    return 0;
}
