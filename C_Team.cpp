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
    int zero, one;
    cin>>zero>>one;

    int mini = (one + 1)/2 -1;
    int maxi = one + 1;

    if(mini<= zero && zero <= maxi)
    {
        vector<int>arr(zero + one,1);
        int i = 1;
        while(zero--)
        {
            arr[i] = 0;
            i +=2;
        }
        for(int i = 2;i<arr.size();i+=2)
        {
            swap(arr[i], arr[i-1]);
        }
        for(auto i : arr)cout<<i;
        
        return;
    }
    else
    {
        cout<<-1<<endl;
        return;
    }
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
        solve();
    

    return 0;
}