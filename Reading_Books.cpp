
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){

   int n;
   cin>>n;
    int sum = 0;
   vector<int>arr(n);
   for(int i =0;i<n;i++) 
   {
        cin>>arr[i];
        sum+=arr[i];
   }
   sort(arr.begin(), arr.end());

   cout<<max(2*arr[n-1], sum);


    return 0;
    
}