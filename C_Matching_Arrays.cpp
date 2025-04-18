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
void rotate(vector<int>&arr, int k)
{
    int n = arr.size();
    vector<int>ans = arr;
    for(int i  = 0;i<n;i++) ans.push_back(arr[i]);

    vector<int>temp;
    for(int i = k;i<ans.size();i++) temp.push_back(ans[i]);
    arr = temp;
}
void solve() {
    int n, k;
    cin>>n>>k;

    vector<int>a(n), b(n);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];

    sort(b.begin(), b.end());

    vector<pair<int, int>>arr;
    for(int i =0;i<n;i++)arr.push_back({a[i], i});

    sort(arr.begin(), arr.end());
    rotate(b, k);
    //for(auto i : b)cout<<i<<" ";
    vector<int>ans(n);
    int cnt = 0;
    
    for(int i = 0;i<n;i++)
    {
        if(arr[i].first > b[i])cnt++;

        ans[arr[i].second] = b[i];
    }

    // int cnt1 = 0;

    // for(int i = 0;i<n;i++)
    // {
    //     if(a[i] > ans[i])cnt1++;
    // }


    //for(auto i : ans)cout<<i<<" ";
   
    if(cnt == k)
    {
        cout<<"YES"<<endl;
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
        return;
    }
    else cout<<"NO"<<endl;


  

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