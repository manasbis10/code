#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;


signed main() {

  int n,a,b;
  cin>>n>>a>>b;

  vector<int>arr(n+1);

  for(int i =1;i<=n;i++)
  {
    cin>>arr[i];
  }
  for(int i =1;i<=n;i++)
  {
    arr[i] += arr[i-1];
  }
  int maxi = LLONG_MIN;

  set<pair<int, int>>st;

  for(int i =a;i<=b;i++)
  {
    st.insert({arr[i], i});
  }

  for(int i =1;i<=n-a+1;i++)
  {
        maxi = max(maxi, (*st.rbegin()).first - arr[i-1]);
        st.erase({arr[i+a-1], i+a -1});

        if(i+b<=n)
        {
            st.insert({arr[i+b], i+b});
        }
  }
  cout<<maxi<<endl;
  return 0;
}