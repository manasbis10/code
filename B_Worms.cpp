#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long


signed main() {
    int n ;
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++) cin>>arr[i];

    int m;
    cin>>m;
    int q[m];
    for(int i =0;i<m;i++) cin>>q[i];

    for(int i =1;i<n;i++)
    {
        arr[i] = arr[i] + arr[i-1];
    }

    vector<int>ans;

    for(auto i : q)
    {
        auto it = lower_bound(arr.begin(), arr.end(), i);
        ans.push_back(it - arr.begin() +1 );
    }

    for(auto i : ans)cout<<i<<endl;

    return 0;
}
