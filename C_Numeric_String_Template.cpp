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
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];

    int m;
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        if(s.length() != n)
        {
            cout<<"NO"<<endl;
            continue;
        }

        vector<int>visited(26);
        map<int, char>mp;
        bool ans = true;
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i]) == mp.end())
            {
                if(visited[s[i] - 'a'] == 0)
                {
                    mp[arr[i]] = s[i];
                    visited[s[i]-'a'] = 1;
                }
                else
                {
                    ans = false;
                    break;

                }
            }
            else
            {
                int x = arr[i];
                char y = mp[arr[i]];

                if(y != s[i])
                {
                    ans = false;
                    break;
                }
            }

        }
        if(ans)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            cout<<"NO"<<endl;
            continue;
        }


    }
  

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