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
  vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;

        for(auto i : nums)
        {
            if(i == 2)
            {
                ans.push_back(-1);
            }
            else
            {
                for(int j = 0; j<=i;j++)
                {
                    if((j | (j + 1)) == i)
                    {
                        ans.push_back(j);
                        break;
                    }
                }
            }
        }
        return ans;
    }
void solve() {
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i = 0;i<n;i++) cin>>a[i];

    vector<int>test = minBitwiseArray(a);

    for(auto i : test)cout<<i<<" ";



    

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