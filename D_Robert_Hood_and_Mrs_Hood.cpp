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
    int n, d, k;
    cin>>n>>d>>k;

    vector<pair<int, int>>arr;

    for(int i = 0;i<k;i++)
    {
       int a, b;
       cin>>a>>b;
       arr.push_back({a, b});
    }

    int amaxi = 1, amini = 1, maxi = INT_MIN, mini = INT_MAX;

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>>pq;
    int j = 0;
    for(int i = 1;i<=n-d + 1;i++)
    {
        
        while(j<k && arr[j].first <= i + d - 1)
        {
            pq.push(arr[j].second);
            j++;
        }
        while(!pq.empty() && pq.top()<i)pq.pop();

       

        if(maxi < (int)pq.size())
        {
            amaxi = i;
   
            maxi = pq.size();
        }
        if(mini > (int)pq.size())
        {
            amini = i;
            mini = pq.size();
        }
    }
    cout<<amaxi<<" "<<amini<<endl;


  

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