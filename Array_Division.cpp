
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int K ;
bool valid(int x, vector<int>&arr)
{
    int t = 1;
    int sum = 0;
    for(int i =0;i<arr.size();i++)
    {
        if(sum + arr[i]<=x) sum+=arr[i];
        else
        {
            t++;
            if(t>K) return false;
            sum = arr[i];
        }
    }
    
    return true;
}
signed main(){

    int n, k;
    cin>>n>>k;
    K = k;

    vector<int>arr(n);
    int maxi = LLONG_MIN;
    int sum = 0;
    for(int i =0;i<n;i++) 
    {
        cin>>arr[i]; 
        maxi = max(maxi, arr[i]);
        sum+=arr[i];
        
    }
    int s = maxi;
    int e = sum;
    int ans = LLONG_MAX;
    while(s<=e)
    {
       
        int mid = s + (e-s)/2;
        
        if(valid(mid, arr))
        {
            ans = min(ans, mid);
            e = mid-1;
        }
        else s = mid+1;
    }
    cout<<ans<<endl;


   

    return 0;
    
}