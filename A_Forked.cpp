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
  int rx, ry;
  cin>>rx>>ry;

  int kx, ky;
  cin>>kx>>ky; 
  int qx, qy;
  cin>>qx>>qy; 

    int directionX[] = { rx,  rx, -rx, -rx,  ry,  ry, -ry, -ry };
    int directionY[] = { ry, -ry,  ry, -ry,  rx, -rx,  rx, -rx };


    map<pair<int, int>, int>mp;
    int cnt = 0;

    for(int i =0;i<8;i++)
    {
        int nx = directionX[i] + kx;
        int ny = directionY[i] + ky;
       // cout<<nx<<" "<<ny<<endl;
        mp[{nx, ny}]++;
    }
   // cout<<"-------------------"<<endl;

    for(int i =0;i<8;i++)
    {
        int nx = directionX[i] + qx;
        int ny = directionY[i] + qy;
       // cout<<nx<<" "<<ny<<endl;
        
        if(mp.find({nx, ny}) != mp.end())cnt++;
    }

    if(rx == ry)
    {
        cnt = cnt/2;
    }
    cout<<cnt<<endl;

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