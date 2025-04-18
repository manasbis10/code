#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
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

    vector<char> alpha;
    vector<int> nums;

    for (auto i : s)
    {
        if (i >= '0' && i <= '9')
        {
            nums.push_back(i - '0');
        }
        else if (i >= 'a' && i <= 'z')
        {
            alpha.push_back(i);
        }
    }
    if (alpha.size() + nums.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            continue;
        else
        {
            if (i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '9')
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i < alpha.size(); i++)
    {
        if (alpha[i] < alpha[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
