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

    vector<string>arr(n);

    for(int i = 0;i<n;i++) cin>>arr[i];

    int top = 0, down = n-1, left = 0, right = m-1;
    int dir = 0;
    string t = "";
    int ans = 0;

    while(top<=down && left <= right)
    {
        if(dir == 0)
        {
            for(int i = left;i<=right;i++)
            {
                t += arr[top][i];
            }
            top++;
        }
        if(dir == 1)
        {
            for(int i = top;i<=down;i++)
            {
                t += arr[i][right];
            }
            right--;
        }
        if(dir == 2)
        {
            for(int i = right;i>=left;i--)
            {
                t += arr[down][i];
            }
            down--;
        }
        if(dir == 3)
        {
            for(int i = down;i>=top;i--)
            {
                t += arr[i][left];
            }
            left++;
        }

        dir = (dir + 1)%4;

        if(dir == 0 || (top > down))
        {
            t += t.substr(0, 3);
          
            for(int i = 0;i<=t.length() - 4;i++)
            {
                if(t.substr(i, 4) == "1543")ans++;
            }
            t.clear();
        }
    }
   
//    if(!t.empty())
//    {
//     cout<<t<<endl;
//         t += t.substr(0, 3);
    
//         for(int i = 0;i<=t.length() - 4;i++)
//         {
//             if(t.substr(i, 4) == "1543")ans++;
//         }
//    }
        
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