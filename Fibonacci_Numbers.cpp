
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int mod = 1e9+7;

vector<vector<int>>mul(vector<vector<int>>&a, vector<vector<int>>&b)
{
    vector<vector<int>>ans(2, vector<int>(2, 0));
    for(int i = 0;i<2;i++)
    {
        for(int j = 0;j<2;j++)
        {
            for(int k = 0;k<2;k++)
            {
                ans[i][j]= (ans[i][j] + a[i][k] * b[k][j])%mod;
            }
        }
    }
    return ans;
}

 vector<vector<int>> matrixExpo( vector<vector<int>>&a, int n )
 {
     if(n==0)
     {
        return {{1,0}, {0,1}};
     }
     if(n==1) return a;
    vector<vector<int>>temp = matrixExpo(a, n/2);
    vector<vector<int>>ans = mul(temp, temp);
    if(n&1) ans = mul(ans, a);

    return ans;
 }

signed main(){

    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }

    vector<vector<int>>a = {{1,1},{1,0}};
    vector<vector<int>>ans = matrixExpo(a, n-1);
    cout<<(ans[0][0])%mod<<endl;

    return 0;
    
}