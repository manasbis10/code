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
vector<vector<int>>dir = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
bool solve(int i, int j,  vector<string>&grid,  vector<vector<int>>&vis, int choice, int n)
{
    if(i == 1 && j == n-1) return true;

    if(i<0 || j < 0 || i>1 || j>=n || vis[i][j]) return false;

    vis[i][j] = 1;

    bool ans = false;
    if(choice == 0)
    {
        for(auto k : dir)
        {
            int nx = i + k[0];
            int ny = j + k[1];
            ans |= solve(nx, ny, grid, vis, 1, n);
        }
        
    }
    else
    {
        if(grid[i][j] == '>')
        {
            ans |= solve(i, j+1, grid, vis, 0, n);
        }
        else
        {
            ans |= solve(i, j-1, grid, vis, 0, n);
        }
    }
   
    return ans;


}
void solve() {
    int n;
    cin>>n;

    vector<string>grid(2);
    for(int i = 0;i<2;i++)
    {
        cin>>grid[i];
    }
    vector<vector<int>>vis(2, vector<int>(n));

    if(solve(0, 0, grid, vis, 0, n))
    {
        cout<<"YES"<<endl;
        return;
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
  

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