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
    string s;
    cin>>s;
    string ans = "";

    int n = s.length();

    if(s.length() == 1)
    {
        if(s[0] == 'a')
        {
            cout<<"wa"<<endl;
            return;
        }
        else
        {
            s.push_back('a');
            cout<<s<<endl;
            return;
        }
    }

    for(int i = 0;i<s.length();i++)
    {
        ans += s[i];
        if(i+1 < n && s[i] == s[i+1])
        {
            if(s[i] == 'a')
            {
                ans += 'b';
                ans += s.substr(i+1);
                break;
            }
            else
            {
                ans += 'a';
                ans += s.substr(i+1);
                break;

            }

        }
        
    }
    if(ans.length() == s.length())
    {
        vector<int>freq(26);
        for(auto i : s)freq[i-'a']++;

        for(int i =0;i<26;i++)
        {
            if(freq[i] == 0)
            {
                string t  = "";
                t += ans[0];
                t +=(i + 'a');
                t += ans.substr(1);
                cout<<t<<endl;
                return;
            }
        }
    }
    cout<<ans<<endl;
  

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