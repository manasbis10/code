#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#include <atcoder/modint>
using mint = modint998244353;



/*---------------------------------------------------------------------------------------*/

void solve() {
	mint n;
	cin>>n;

	vector<mint>arr(n);

	for(mint i = 0;i<n;i++) cin>>arr[i];
	
	vector<vector<map<mint, mint>>>dp(n, vector<map<mint, mint>>(n+1));

	for(mint i = 0;i<n;i++) dp[i][1][0] = i+1;
	
	for(mint i = 0;i<n;i++)
	{
		for(mint k = 2;k<=n;k++)
		{
			for(mint j = i+1;j<n;j++)
			{
				mint diff = arr[j] - arr[i];
				if(k==2)
				{
					dp[j][k][diff]++;
					continue;
				}
				dp[j][k][diff] += dp[i][k-1][diff];
			}
		}
	}

	for(mint k = 1;k<=n;k++)
	{
		if(k==1)
		{
			cout<<n<<" ";
			continue;
		}
		mint ans = 0;
		for(auto i : dp)
		{
			
			for(auto j : i[k])
			{
				ans += j.second;
			}

		}
		cout<<ans<<" ";
	}


	

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
       solve();
    

    return 0;
}