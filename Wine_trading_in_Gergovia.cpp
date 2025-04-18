#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/
bool check(int a, int b)
{
    if(a >= 0 && b < 0) return true;
    if(a < 0 && b >= 0) return true;
    return false;

}
void solve() {
    while(1)
    {
        int n;
        cin>>n;
        if(n == 0)
        {
            return;
        }

        vector<int>arr(n);
        for(int i = 0;i<n;i++) cin>>arr[i];

        stack<pair<int, int>>st;
        int cnt = 0, ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({arr[i], i});
                continue;
            }
            while(!st.empty() && check(st.top().first, arr[i]))
            {
                auto top = st.top();
                st.pop();
                if(abs(arr[i]) >= abs(top.first))
                {
                    ans += (i - top.second)*(min(abs(arr[i]), abs(top.first)));
                    arr[i] = arr[i] + top.first;
                    if(arr[i] == 0)break;
                    continue;
                }
                else
                {
                    
                    ans += (i - top.second)*(min(abs(arr[i]), abs(top.first)));
                    st.push({arr[i] + top.first, top.second});
                    arr[i] = 0;
                    break;
                }

            }
            if(arr[i] != 0)
            st.push({arr[i], i});
        }
        cout<<ans<<endl;
    }
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}