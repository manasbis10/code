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
    int n;
    cin >> n;

    string s;
    cin >> s;
    int ans = 0;

    stack<pair<char, int>> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '_')
        {
            if (!st.empty() && st.top().first == '(')
            {
                auto top = st.top();
                st.pop();
                ans += i - top.second;
            }
            else
            {
                st.push({'(', i});
            }
        }
        else if (s[i] == ')')
        {
            auto top = st.top();
            st.pop();
            ans += i - top.second;
        }
        else
            st.push({s[i], i});
    }
    cout<<ans<<endl;
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