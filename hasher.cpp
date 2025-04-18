#include <bits/stdc++.h>

using namespace std;

int quickHash(string s, int p, int mod)
{
    int ans = s[0] - 'a' + 1;
    for (int i = 1; i < s.length(); i++)
    {
        ans = (ans * p + (s[i] - 'a' + 1)) % mod;
    }
    return ans;
}

struct hasher
{
    int n, _p, _mod;

    vector<int> fhash, powk;

    void init(string &s, int p, int mod)
    {
        n = s.length();
        _p = p;
        _mod = mod;

        fhash.resize(n);
        powk.resize(n);

        powk[0] = 1;
        fhash[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++)
        {
            fhash[i] = (p * fhash[i - 1] + (s[i] - 'a' + 1)) % mod;
            powk[i] = (powk[i - 1] * p) % mod;
        }
    }

    int getHash(int l, int r)
    {
        if (l == 0)
            return fhash[r];
        return (fhash[r] - (fhash[l - 1] * powk[r - l + 1]) % _mod + _mod) % _mod;
    }
};

struct doubleHash
{

    hasher a;
    hasher b;

    void init(string s)
    {
        a.init(s, 37, 1000000021);
        b.init(s, 39, 1000000009);
    }
    pair<int, int> getHash(int l, int r)
    {
        return {a.getHash(l, r), b.getHash(l, r)};
    }
};