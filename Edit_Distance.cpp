#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int mod = 1e9+7;

signed main() {
   
    string s1, s2;
    cin>>s1>>s2;

//     int n = s1.length();
//     int m = s2.length();

//     vector<vector<int>>dp(n+1, vector<int>(m+1));
   
//    for(int i =0;i<=n;i++)
//    {
//         dp[i][0] = i;
//    }
//    for(int i =0;i<=m;i++)
//    {
//         dp[0][i] = i;
//    }

//     for(int i =1;i<=n;i++)
//     {
//         for(int j = 1;j<=m;j++)
//         {
//             if(s1[i-1]==s2[j-1])
//             {
//                 dp[i][j] = dp[i-1][j-1];
//             }
//             else 
//             {
//                 dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
//             }
//         }
//     }
//     cout<<dp[n][m]<<endl;

for(int i = 0;i<=400000;i++)
{
    for(int j = i;j<=400000;j++)
    {
        if(i*i + j*j == 2038480973)
        {
            cout<<i<<" "<<j;
            break;
        }
    }
}

    
    return 0;
}
