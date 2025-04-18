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
    int n = arr.size(), ored = 0;
    vector<int>bit(31);

    for(int i = 0;i<mid;i++)
    {
        for(int j = 0;j<31;j++)
        {
            if(arr[i] &(1<<j))
            {
                bit[j]++;
            }
        }
    }
    for(int j = 0;j<31;j++)
        {
            if(bit[j])
            {
               ored |= (1<<j);
            }
        }
    for(int i = mid;i<n;i++)
    {
        for(int j = 0;j<31;j++)
        {
            if(arr[i] &(1<<j))
            {
                bit[j]++;
            }
        }
        int el = arr[i - mid];

        for(int j = 0;j<31;j++)
        {
            if(el &(1<<j))
            {
                bit[j]--;
            }
        }
        int tempOr = 0;
        for(int j = 0;j<31;j++)
        {
            if(bit[j])
            {
               tempOr |= (1<<j);
            }
        }
        if(tempOr != ored)return false;

    }
    return true;

}
void solve() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++) cin>>arr[i];

    int start = 1, end = n, ans = 0;

    while(start <= end)
    {
        int mid = start  + (end - start)/2;

        if(check(mid, arr))
        {
            ans = mid;
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
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