#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;

bool solve(int mid, vector<int>&arr)
{
    int i = arr.size() - 1;
    bool ans = true;
    for(int j = mid-1;j>=0;j--)
    {
        ans = ans && (arr[j]<arr[i]) && (arr[j]<arr[i-1]);
        i--;
    }
    return ans;
}

signed main() {

   int n;
   cin>>n;

   vector<int>arr(n);
   for(int i =0;i<n;i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
   int l = 1, r= (n+1)/2 - 1, ans = 0;
   while(l<=r)
   {
         int mid = l + (r - l)/2;
         if(solve(mid, arr))
         {
            ans = mid;
            l = mid +1;
         }
         else r = mid - 1;
   }
   cout<<ans<<endl;
   int i = n - 1, j = ans - 1;
   vector<int>temp(n);

   for(int k = 0;k<n;k++ )
   {
        if(k%2==0 || j==-1) temp[k] = arr[i--];
        else temp[k] = arr[j--];
   }
   for(auto i : temp)
   {
    cout<<i<<" ";
   }

    return 0;
}