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
vector<vector<int>>build(vector<int>&arr)
{
    int n = arr.size();
    vector<vector<int>>temp(n, vector<int>(31));

    for(int i = 0;i<31;i++)
    {
        if(arr[0] & (1<<i))temp[0][i]++;
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<31;j++)
        {
            if(arr[i] & (1<<j))
            {
                temp[i][j] = temp[i-1][j] + 1;
            }
            else
            {
                temp[i][j] = temp[i-1][j];
            }
        }
    }
    return temp;
}
void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];
    vector<vector<int>>bits = build(arr);
    int q;
    cin>>q;

    auto check = [&](int mid, int l, int k)
    {
        int ans = 0;
        for(int i = 0;i<31;i++)
        {
            if(l-1>=0 && (bits[mid][i] - bits[l - 1][i]) == (mid - l + 1))
            {
                ans += (1<<i);
            }
            if(l == 0 && (bits[mid][i] - 0) == (mid - l + 1))
            {
                ans += (1<<i);
            }
        }
        
        return ans >= k;
    };

    while(q--)
    {
        int k, l;
        cin>>l>>k;

        l--;
        if(arr[l] < k)
        {
            cout<<-1<<" ";
            continue;
        }
        int start = l, end = n-1;
        int ans = -1 ;

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(check(mid, l, k))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
 
         cout<<ans + 1<<" ";

       
    }
    cout<<endl;
  

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