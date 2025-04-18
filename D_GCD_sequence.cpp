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
bool check(vector<int>&arr, int idx)
{
    if(idx < 0) return false;

    vector<int>temp;
    for(int i = 0;i<arr.size();i++)
    {
        if(idx == i)continue;
        temp.push_back(arr[i]);
    }
    int n = temp.size();
    int prev = -1;
    
     for(int i = 0;i<n-1;i++)
    {
        if(gcd(temp[i], temp[i+1]) < prev)
        {
            return false;
        }
        prev = gcd(temp[i], temp[i+1]);
    }
    return true;

}
void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    int idx = -1, prev = -1;

    for(int i = 0;i<n-1;i++)
    {
        if(gcd(arr[i], arr[i+1]) < prev)
        {
            idx = i;
            break;
        }
        else prev = gcd(arr[i], arr[i+1]);
    }
    
    if(idx == n-2)
    {
        cout<<"YES"<<endl;
        return;
    }

    bool ans = check(arr, idx - 1) || check(arr, idx) ||
    check(arr, idx + 1);
    
    if(ans)
    {
        cout<<"YES"<<endl;
        return;
    }
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