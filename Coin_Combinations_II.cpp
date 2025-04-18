#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 1e9+7;

signed main() {
   
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(target + 1,0));

    for(int i = 0; i <= target; i++) {
        if(i % arr[0] == 0)
            dp[0][i] = 1;
    }
    for(int i =0;i<n;i++) dp[i][0] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= target; j++) {
            int ex = dp[i - 1][j];
            int inc = 0;
            if(j - arr[i] >= 0)
                inc = dp[i][j - arr[i]];

            dp[i][j] = inc+ex;
        }
    }

    cout << dp[n - 1][target] << endl;
    return 0;
}
