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

    int prev = 1, curr= 0;
    

    for(int i = 2; i<=n ;i++)
    {
        curr = (prev*1LL*3)%mod;
        if(i%2==0)
        prev = curr-1;
        else
        prev = curr+1;

    }
    
    cout<<curr<<endl;
    return 0;
}