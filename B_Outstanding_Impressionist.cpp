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
    map<int, int>mp;
    
    vector<int>el;
    int maxi = -1;
    vector<pair<int, int>>arr;
    for(int i = 0;i<n;i++)
    {
        int a, b;
        cin>>a>>b;
        if(a== b)
        {
            if(mp.count(a) == 0)
            {
                el.push_back(a);
            }
            mp[a]++;

        }
       
        arr.push_back({a,b});

    }
    sort(el.begin(), el.end());
    
    string ans = "";
    for(auto i : arr)
    {
        int l = i.first;
        int r = i.second;
        if(l == r)
        {
            if(mp[l] == 1)
            {
                ans += '1';
            }
            else
            {
                ans +='0';
            }
            continue;
        }

        auto left = lower_bound(el.begin(), el.end(), l);
        auto right = upper_bound(el.begin(), el.end(), r);
        
        // if(left == el.begin() || right == el.begin())
        // {
        //      ans +='1';
        //      continue;
        // }
        if(right != el.begin())right--;
        
       

        //cout<<left<<" "<<right<<endl;
      
        ans += ((right - left + 1) == ( r - l + 1)) ? '0' : '1';
        

      
       
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