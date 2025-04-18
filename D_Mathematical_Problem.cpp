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

int solve(int i, string s, int taken, int mul_sum, int cnt)
{
    if (cnt == 0)
    {
        return stoll(s.substr(i));
    }
    if (i == s.length() - 1)
        return stoll(s.substr(i));
    if (i >= s.length())
    {
        if (mul_sum == 1)
            return 1;
        else
            return 0;
    }
    int res = LLONG_MAX, ans = LLONG_MAX, ans1 = LLONG_MAX, ans2 = LLONG_MAX, ans3 = LLONG_MAX;
    if (taken == 0)
    {
        // cout<<"hi"<<endl;
        if (i + 2 <= s.length())
        {
            ans = stoll(s.substr(i, 2)) + solve(i + 2, s, 1, 0, cnt - 1);
            ans1 = stoll(s.substr(i, 2)) * solve(i + 2, s, 1, 1, cnt - 1);
        }

        ans2 = stoll(s.substr(i, 1)) + solve(i + 1, s, 0, 0, cnt - 1);
        ans3 = stoll(s.substr(i, 1)) * solve(i + 1, s, 0, 1, cnt - 1);
        // cout<<ans<<ans1<<ans2<<ans3<<endl;
        res = min({ans, ans1, ans2, ans3, res});
    }
    else
    {
        ans = stoll(s.substr(i, 1)) + solve(i + 1, s, 1, 0, cnt - 1);
        ans1 = stoll(s.substr(i, 1)) * solve(i + 1, s, 1, 1, cnt - 1);
        // cout<<ans<<ans1<<ans2<<ans3<<endl;
        res = min({res, ans, ans1});
    }
    return  res;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    

    if(n<=2)
    {
        int ans = stoll(s.substr(0));
        cout<<ans<<endl;
        return;
    }
    if(s[0] == '0')
    {
        cout<<0<<endl;
        return;
    }

    int ans = solve(0, s, 0, -1, n - 2);
    cout << ans << endl;
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