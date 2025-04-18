
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool valid(int k, vector<int>&arr, int t)
{
    int sum = 0;
    for(int i =0;i<arr.size();i++)
    {
        sum+= k/arr[i];
    }
    
    return sum>=t;
}
signed main(){

   int n, k;
   cin>>n>>k;

   vector<int>arr(n);
   for(int i =0;i<n;i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
   int s = 0;
   int e = arr[0]*k;
   
    int ans = LLONG_MAX;
   while(s<=e)
   {
        int mid = s + (e-s)/2;

        if(valid(mid, arr, k))
        {
            ans = min(ans, mid);
            e = mid-1;
        }
        else
        s = mid+1;
   }
    cout<<ans;
    
    return 0;
    
}