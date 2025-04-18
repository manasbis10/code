#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int n;
   cin>>n;


   if(n&1)
   {
        cout<<0<<endl;
        return 0;
   }

   int ans = 0;
   int power = 10;
   int a = n;

   while(a)
   {
        int t = n/power;
        ans+= t;
        power = power*5;
        a = t;
   }

   cout<<ans<<endl;
 
    return 0;
}