#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i =0;i<n;i++) cin>>arr[i];

    int ans = 0;

    int i =0, j= n-1;

    while(i<j)
    {
        ans = gcd(ans, abs(arr[j] - arr[i]));
        i++;
        j--;
    }

    cout<<ans<<endl;
}

signed main() {

   int tc;
   cin>>tc;
   while(tc--)
   {
        solve();
   }
   return 0;
  
}