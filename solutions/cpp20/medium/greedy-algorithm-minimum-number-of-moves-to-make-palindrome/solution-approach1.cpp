// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-minimum-number-of-moves-to-make-palindrome/problem?isFullScreen=true
// Problem     Greedy Algorithm - Minimum Number of Moves to Make Palindrome
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:06 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int moves = 0;

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else
        {
            int k = right;

            while (k > left && s[k] != s[left])
                k--;

            if (k == left)
            {
                swap(s[left], s[left + 1]);
                moves++;
            }
            else
            {
                while (k < right)
                {
                    swap(s[k], s[k + 1]);
                    k++;
                    moves++;
                }

                left++;
                right--;
            }
        }
    }

    cout << moves;

    return 0;
}
