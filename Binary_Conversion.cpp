#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/

void solve() {

    int n, k;
    cin>>n>>k;

    string s1, s2;
    cin>>s1>>s2;

    int a = 0, b = 0;

    for(auto i : s1)
    {
        if(i=='1') a++;
    }
    for(auto i : s2)
    {
        if(i=='1') b++;
    }

    if(a != b)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(n==2)
    {
        if(s1 != s2)
        {
            if(k&1)
            {
                cout<<"YES"<<endl;
                return;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else
        {
            if((s1[0] == '0' && s1[1] == '0') || (s1[0] == '1' && s1[1] == '1'))
            {
                cout<<"YES"<<endl;
                return;

            }
            else
            {
                if(k&1)
                {
                    cout<<"NO"<<endl;
                    return;
                }
                else
                {
                    cout<<"YES"<<endl;
                    return;
                }
            }
        }

    }

    int diff = 0;
    for(int i = 0;i<n;i++)
    {
        if(s1[i] != s2[i])
        {
            diff++;
        }
    }
    int min_swaps = diff/2;
    
    if(diff & 1)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(min_swaps<=k)
    {

        cout<<"YES"<<endl;
        return;
    }
    else
    cout<<"NO"<<endl;


}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}