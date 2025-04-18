#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
int mod = 1e9+7;



signed main() {

 int n, m;
 cin>>n>>m;

 vector<int>a1(n), a2(m);

 for(int i =0;i<n;i++) cin>>a1[i];
 for(int i =0;i<m;i++) cin>>a2[i];

 int i = 0, j=0;
 int count = 0;
 while(i<n && j<m)
 {
    if(a1[i]==a2[j])
    {
        int temp = a1[i];
        int c1 = 0, c2 = 0;

        while(i<n && a1[i]==temp)
        {
            c1++;
            i++;
        }

        while(j<m && a2[j]==temp)
        {
            c2++;
            j++;
        }
        count += c1*c2;
    }
    else if(a1[i]>a2[j])
    {
        j++;
    }
    else{
        i++;
    }
 }
cout<<count<<endl;
 return 0;
  
}