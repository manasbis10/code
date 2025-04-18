#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_sub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int bin_exp(int base, int exp, int m)
{
    if (exp == 0)
        return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0)
    {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) { return bin_exp(a, m - 2, m); }
/*---------------------------------------------------------------------------------------*/

void solve()
{
    int q;
    cin >> q;
    vector<int> s(26), t(26);
    s[0] = 1;
    t[0] = 1;

    int maxiA = 0, maxiB = 0;

    while (q--)
    {
        int type, k;
        cin >> type >> k;
        string x;
        cin >> x;

        if (type == 1)
        {
            for (auto i : x)
            {
                maxiA = max(maxiA, (i - 'a')*1LL);
                s[i - 'a'] = s[i - 'a'] + k;
            }
        }
        else
        {
            for (auto i : x)
            {
                t[i - 'a'] = t[i - 'a'] + k;
                maxiB = max(maxiB, (i - 'a')*1LL);
            }
        }
        
        if (maxiB > 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else if (maxiA == maxiB)
        {
            if (s[0] < t[0])
            {
                cout << "YES" << endl;
                continue;
            }
            else
            {
                cout << "NO" << endl;
                continue;
            }
        }
        else if(maxiA > maxiB)
        {
            cout<<"NO"<<endl;
            continue;
        }
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}