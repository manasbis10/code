#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;

void solve()
{
    int m, x;
    cin>>m>>x;

    vector<int>arr(m);

    for(int i =0;i<m;i++) cin>>arr[i];

    priority_queue<int>pq;
    int sum = 0;

    for(int i =0;i<m;i++)
    {
        if(sum>=arr[i])
        {
            pq.push(arr[i]);
            sum-=arr[i];
        }
        else if(!pq.empty() && pq.top() > arr[i])
        {
            sum+= pq.top() - arr[i];
            pq.pop();
            pq.push(arr[i]);
        }
        sum+=x;
    }
    cout<<pq.size()<<endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;

    while(tc--)
    {
        solve();
    }
 
    return 0;
}