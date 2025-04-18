#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'

int mod = 1e9+7;
int main() {
   int n;
   cin>>n;
   vector<int>ans(n+1);

  

   for(int i =n;i>=2;i--)
   {
        cout<<"? "<<1<<" "<<i<<endl;
        int res;
        cin>>res;
        ans[i] = res;
   }
   cout<<"? "<<2<<" "<<n<<endl;
    int res;
    cin>>res;
    ans[1] = ans[n] - res;
   cout<<"! "<<ans[1]<<" ";
   for(int i =2;i<=n;i++)
   {
        cout<<ans[i] - ans[i-1]<<" ";
   }
    
    
 
    return 0;
}