#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
int mod = 1e9+7;
signed main() {
   
    vector<int>arr(6);
    int a,b, c,d;
    cout<<"? "<<1<<" "<<2;
    cout<<endl;
    cout.flush();
    cin>>a;
    cout<<"? "<<2<<" "<<3;
    cout<<endl;
    cout.flush();
    cin>>b;

    arr[1] = gcd(a, b);
    arr[0] = a/arr[1];
    arr[2] = b/arr[1];

    cout<<"? "<<4<<" "<<5;
    cout<<endl;
    cout.flush();
    cin>>c;
    cout<<"? "<<5<<" "<<6;
    cout<<endl;
    cout.flush();
    cin>>d;

    arr[4] = gcd(c, d);
    arr[3] = c/arr[4];
    arr[5] = d/arr[4];

    cout<<"! ";
    for(auto i : arr) cout<<i<<" ";



    return 0;
}