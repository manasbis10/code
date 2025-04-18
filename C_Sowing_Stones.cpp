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
    int n, m;
    cin>>n>>m;

    vector<int>a(m), b(m);

    for(int i = 0;i<m;i++)
    {
        cin>>a[i];
    }
     for(int i = 0;i<m;i++)
    {
        cin>>b[i];
    }
    vector<pair<int, int>>arr(m);
     for(int i = 0;i<m;i++)
    {
        arr[i] = {a[i], b[i]};
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 0;i<m-1;i++)
    {
        if(arr[i].second < abs(arr[i+1].first - arr[i].first))
        {
            cout<<-1<<endl;
            return;
        }
        int diff = arr[i+1].first - arr[i].first ;
        int a = arr[i].second;
        arr[i+1].second += arr[i].second - (arr[i+1].first - arr[i].first);

        ans += (diff*a) - ((diff*(diff+1))/2);
    }
    
    if(arr[m-1].second + arr[m-1].first - 1 != n)
    {
        cout<<-1<<endl;
        return;
    }

    int diff = n - arr[m-1].first ;
    int a1 = arr[m-1].second;

    int last = (diff*a1) - ((diff*(diff+1))/2);

    

    cout<<ans + last;


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    

    return 0;
}