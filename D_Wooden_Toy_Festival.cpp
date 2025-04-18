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
bool check(int mid, vector<int>&arr)
{
    int cnt = 1, n = arr.size();
    int curr = arr[0] + mid;
    for(int i = 0;i<n;i++)
    {
        if(abs(curr - arr[i]) <= mid) continue;
        else
        {
            curr = arr[i] + mid;
            cnt++;
            if(cnt>3)
            {
                return false;
            }
        }
    }
    return true;
}
void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i  =0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());

    int start = 0, end = 1e15, ans = 0;

    while(start<=end)
    {
        int mid = start + (end - start)/2;

        if(check(mid, arr))
        {
            ans = mid;
            end = mid - 1;
        }
        else start = mid + 1;
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