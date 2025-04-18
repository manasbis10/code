#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                        tree_order_statistics_node_update>;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i =0;i<n;i++) cin>>arr[i];

    ordered_set<pair<int, int>> st;
    for(int i = 0;i<k;i++) st.insert({arr[i],i});

    auto el = *(st.find_by_order((k-1)/2));
    cout<<el.first<<" ";
    for(int i = k;i<n;i++)
    {
        st.erase({arr[i - k], i-k});
        st.insert({arr[i], i});
        auto el = *(st.find_by_order((k-1)/2));
        cout<<el.first<<" ";
    }



    return 0;
}
