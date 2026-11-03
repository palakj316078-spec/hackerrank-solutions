// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/greedy-algorithm-lemonade-change/problem?isFullScreen=true
// Problem     Greedy Algorithm - Lemonade Change
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:02 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int five = 0;
    int ten = 0;

    for (int i = 0; i < n; i++)
    {
        int bill;
        cin >> bill;

        if (bill == 5)
        {
            five++;
        }
        else if (bill == 10)
        {
            if (five == 0)
            {
                cout << "false";
                return 0;
            }

            five--;
            ten++;
        }
        else
        {
            if (ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
            {
                five -= 3;
            }
            else
            {
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";

    return 0;
}
