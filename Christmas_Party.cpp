#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n+1);
    arr[0] = 1;
    arr[2] = 1;

    for(int i = 3;i<=n;i++)
    {
        arr[i] = ((i-1)*((arr[i-1] + arr[i-2])%mod))%mod;
    }

    cout<<arr[n]<<endl;
 
    return 0;
}