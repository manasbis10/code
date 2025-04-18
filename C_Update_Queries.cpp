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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        arr[i] = a;
    }
    set<int>st;
    for(auto i : arr)st.insert(i);

    // sort(arr.begin(), arr.end());

    string c;
    cin >> c;

    sort(c.begin(), c.end());
    int c_i = 0;

    string ans = "";

    map<int, char> mp;

    for (auto i : st)
    {
        
            mp[i] = c[c_i];
        
        c_i++;
    }
    //for(auto i : mp) cout<<i.first<<" "<<i.second<<endl;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(i) != mp.end())
        {
            ans += mp[i];
        }
        else
        {
            ans += s[i];
        }
    }
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