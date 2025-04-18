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
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin >> s;

    set<char> st;
    for (auto i : s)
        st.insert(i);

    int i = 0, j = 0;

    int ans = INT_MAX;
    map<char, int>mp;
    while(j<n)
    {
        mp[s[j]]++;
        if(mp.size() == st.size())
        {
            
            while(mp.size()==st.size())
            {
                ans = min(ans, j - i +1);
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    cout<<ans<<endl;
    return 0;
}
