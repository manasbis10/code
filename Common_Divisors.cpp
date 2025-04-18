#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

   int n;
   cin>>n;

   int maxi = INT_MIN;
    vector<int>arr(n);
   for(int i = 0;i<n;i++)
   {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
   }
   vector<int>freq(maxi+1);

   for(int i = 0;i<n; i++) freq[arr[i]]++;

   for(int i = freq.size() - 1; i>=0; i--)
   {
        int count = 0;
        for(int j = i; j<freq.size();j=j+i)
        {
            count+=freq[j];
            if(count>=2)
            {
                cout<<i<<endl;
                return 0;
            }
        }
   }
   cout<<1<<endl;
   return 0;
  
}