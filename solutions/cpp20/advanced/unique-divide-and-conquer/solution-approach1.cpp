// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/contests/ku-uit-daa/challenges/unique-divide-and-conquer/problem?isFullScreen=true
// Problem     Unique Divide And Conquer       
// Difficulty  Advanced
// Subdomain   Algorithms
// Platform    HackerRank
// Language    cpp20
// Status      Accepted
// Submitted   2026-11-03, 07:58 a.m.
// ──────────────────────────────────────────────────

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll mod;

vector<ll> fact, invFact;
vector<ll> f, dp;

ll power(ll a, ll b)
{
    ll res = 1;

    while (b)
    {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll C(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    return fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> mod;

    fact.resize(n + 1);
    invFact.resize(n + 1);
    f.resize(n + 1);
    dp.resize(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    invFact[n] = power(fact[n], mod - 2);

    for (int i = n; i >= 1; i--)
        invFact[i - 1] = invFact[i] * i % mod;

    f[1] = 1;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = dp[i - 1];

        for (int j = (i + 1) / 2; j < i; j++)
        {
            ll ways = C(i - 1, j);
            ways = ways * j % mod;
            ways = ways * f[j] % mod;
            ways = ways * dp[i - j - 1] % mod;

            f[i] = (f[i] - ways + mod) % mod;
        }

        f[i] = f[i] * i % mod;

        for (int j = 1; j <= i; j++)
        {
            ll ways = C(i - 1, j - 1);
            ways = ways * j % mod;
            ways = ways * f[j] % mod;
            ways = ways * dp[i - j] % mod;

            dp[i] = (dp[i] + ways) % mod;
        }
    }

    cout << f[n] << '\n';

    return 0;
}
