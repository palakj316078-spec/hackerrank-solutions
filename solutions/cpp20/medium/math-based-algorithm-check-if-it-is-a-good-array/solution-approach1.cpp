// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/math-based-algorithm-check-if-it-is-a-good-array/problem?isFullScreen=true
// Problem     Math Based Algorithm - Check If It Is a Good Array
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 08:20 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main()
{
    int n;
    cin >> n;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        ans = gcd(ans, x);
    }

    if (ans == 1)
        cout << "True";
    else
        cout << "False";

    return 0;
}
