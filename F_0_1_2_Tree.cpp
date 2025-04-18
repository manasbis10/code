#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
 int a, b,c;
 cin>>a>>b>>c;
 if((3*a + 2*b + c -1 )&1)
 {
    cout<<-1<<endl;
    return;
 }
 int ans = floor(log2(a+b+c) + 1);
 cout<<ans<<endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
