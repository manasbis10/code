#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
bool valid(int mid, vector<int>cities, vector<int>towers)
{
    vector<int>dist;
    for(auto i : towers)
    {
        
        int right = i + mid;
        dist.push_back(right);
    }
    int cnt = 0;
    for(int i =0;i<cities.size();i++)
    {
        int index = lower_bound(dist.begin(), dist.end(), cities[i]) - dist.begin();

        if(index!=dist.size() && towers[index]-mid<=cities[i])
        {
            cnt++;
        }
        
    }
    return cnt==cities.size();
}

signed main() {
    int n,m ;
    cin>>n>>m;
    
    vector<int>cities(n), towers(m);

    for(int i =0;i<n;i++) cin>>cities[i];
    for(int i =0;i<m;i++) cin>>towers[i];

    int s = 0;
    int e = 1e10;
    int ans = -1;
    while(s<=e)
    {
        int mid = s + (e - s)/2;

        if(valid(mid, cities, towers))
        {
            ans = mid;
            e = mid -1;
        }
        else 
        {
            s = mid + 1;
        }
    }

    cout<<ans<<endl;



    return 0;
}