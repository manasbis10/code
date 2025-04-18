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
    int n,m;
    cin>>n>>m;

    int x,y;
    cin>>x>>y;
    x--;y--;

    vector<vector<char>>arr(n, vector<char>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    string dir;
    cin>>dir;

    for(auto d : dir)
    {
        int i = 0, j =0;
        char move = d;
        if(d == 'L')
        {
            i = 0, j= -1;
        }
        else  if(d == 'R')
        {
            i = 0, j= 1;
        }
        else  if(d == 'U')
        {
            i = -1, j= 0;
        }
        else  if(d == 'D')
        {
            i = 1, j= 0;
        }

        int nx = x + i;
        int ny = y + j;

        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny] == '.')
        {
            x = nx;
            y = ny;         
        }
    }
    cout<<x+1<<" "<<y+1<<endl;

  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}