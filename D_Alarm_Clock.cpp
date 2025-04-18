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

     int n, m, k;
     cin>>n>>m>>k;

     vector<int>arr(n);
     for(int i = 0;i<n;i++) cin>>arr[i];
     sort(arr.begin(), arr.end());

     
     deque<int>dq;

     int ans = 0;

     for(int i = 0;i<n;i++)
     {
        int el = arr[i];
        dq.push_back(el);

        while(dq.back() - dq.front() + 1>m)dq.pop_front();
        
        while(dq.size()>=k)
        {
            ans++;
            dq.pop_back();
        }
     }
     cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}