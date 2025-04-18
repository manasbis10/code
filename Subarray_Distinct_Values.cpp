
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){

   int n, k;
   cin>>n>>k;

   vector<int>arr(n);
   for(int i =0;i<n;i++) cin>>arr[i];

   map<int , int>mp;
   int j=0;
   int cnt = 0;

  for(int i =0;i<n;i++)
  {
    while(j<n && (mp.size()<k || mp.count(arr[j])>0))
    {
        mp[arr[j]]++;
        j++;
    }
    cnt+=j-i;
    mp[arr[i]]--;
    if(mp[arr[i]]==0) mp.erase(arr[i]);
  }
   cout<<cnt<<endl;

    return 0;
    
}