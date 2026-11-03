// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/backtracking-restore-ip-addresses/problem?isFullScreen=true
// Problem     Backtracking- Restore IP Addresses
// Difficulty  Medium
// Subdomain   N/A
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 09:08 a.m.
// ──────────────────────────────────────────────────

#include <iostream>
#include <string>
using namespace std;

string s;
bool found = false;

bool valid(string part)
{
    if (part.length() > 1 && part[0] == '0')
        return false;

    int num = stoi(part);

    return num >= 0 && num <= 255;
}

void generate(int index, int parts, string current)
{
    if (parts == 4)
    {
        if (index == s.length())
        {
            cout << current << endl;
            found = true;
        }

        return;
    }

    for (int len = 1; len <= 3 && index + len <= s.length(); len++)
    {
        string part = s.substr(index, len);

        if (!valid(part))
            continue;

        if (parts == 3 && index + len != s.length())
            continue;

        if (parts < 3)
            generate(index + len, parts + 1, current + part + ".");
        else
            generate(index + len, parts + 1, current + part);
    }
}

int main()
{
    cin >> s;

    if (s.length() < 4 || s.length() > 12)
    {
        cout << -1;
        return 0;
    }

    generate(0, 0, "");

    if (!found)
        cout << -1;

    return 0;
}
