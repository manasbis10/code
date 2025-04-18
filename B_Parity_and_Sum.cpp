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

    vector<int>even, odd;

    for(int i = 0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a&1)
        {
            odd.push_back(a);
        }
        else
        {
            even.push_back(a);
        }
    }
    if(odd.size() == 0 || even.size() == 0)
    {
        cout<<0<<endl;
        return;
    }
    sort(odd.begin(), odd.end());
    multiset<int>s;
    for(auto i : even) s.insert(i);

    int maxi = odd[odd.size() -1], ans = 0;

    while(!s.empty())
    {
        auto it = lower_bound(s.begin(), s.end(), maxi);
        if(it == s.end())
        {
            ans += s.size();
            cout<<ans<<endl;
            return;
        }
        if(it == s.begin())
        {
            ans += 2 + s.size() - 1;
            cout<<ans<<endl;
            return;
        }
        it--;
        int el = *it;
        maxi = maxi + el;
        s.erase(it);
        ans++;
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