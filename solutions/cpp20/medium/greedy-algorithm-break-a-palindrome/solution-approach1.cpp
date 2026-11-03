// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-break-a-palindrome/problem?isFullScreen=true
// Problem     Greedy Algorithm - Break a Palindrome
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:04 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    if (n == 1)
    {
        cout << "";
        return 0;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != 'a')
        {
            s[i] = 'a';
            cout << s;
            return 0;
        }
    }

    s[n - 1] = 'b';

    cout << s;

    return 0;
}
