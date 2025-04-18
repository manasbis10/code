#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

    int n, k, m;
    cin>>n>>k>>m;

    vector<int>arr(n);

    for(int i =0;i<n;i++) cin>>arr[i];

    map<int , int>mp;
    for(auto i : arr) mp[i % m]++;

    for(auto i : mp)
    {
        if(i.second>=k)
        {
            cout<<"Yes"<<endl;
            for(auto j : arr)
            {
                
                if(j%m== i.first && k>0)
                {
                    cout<<j<<" ";   
                    k--;
                } 
            }
            return 0;

        }
    }
    cout<<"No"<<endl;
   return 0;
  
}