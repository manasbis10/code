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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int>a(n), b(m);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<m;i++) cin>>b[i];

    map<int, int>mp1, mp2;
    int total = 0;
    for(auto i : b)
    {
        mp2[i]++;
    }

    for(int i = 0;i<m;i++)
    {
        if(mp1[a[i]]<mp2[a[i]])
        {
            total++;
        }
        if(mp2.count(a[i]))
        mp1[a[i]]++;

    }
  
    int cnt = 0;
    if(total>=k)cnt++;
    
   
    for(int i = m;i<n;i++)
    {
        int prev = i - m;
        if(mp1[a[prev]] != 0)
        {
            mp1[a[prev]]--;
            if(mp1[a[prev]]<mp2[a[prev]])
            {
                total--;
            }
        }
        if(mp1[a[i]]<mp2[a[i]])
        {
            total++;
        }
        if(mp2.count(a[i]))
        mp1[a[i]]++;

         
        if(total>=k)cnt++;
    }

    cout<< cnt<<endl;


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
