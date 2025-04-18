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


signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin>>a>>b>>c;
    map<int, int>mp;
    mp[0] = a;
    mp[1] = b;
    mp[2] = c;


    int m;
    cin>>m;

    vector<pair<int, int>>mouse;

    for(int i = 0;i<m;i++)
    {
        int a;
        cin>>a;
        string s;
        cin>>s;

        if(s=="USB")
        {
            mouse.push_back({a, 0});
        }
        else{
            mouse.push_back({a, 1});
        }
    }

    sort(mouse.begin(), mouse.end());

    int count = 0, price = 0;

    for(auto i : mouse)
    {
        int cost = i.first;
        int type = i.second;

        if(mp[type])
        {
            price += cost;
            mp[type]--;
            count++;
        }
        else{
            if(mp[2])
            {
                price += cost;
                mp[2]--;
                count++;
            }
        }
    }
    cout<<count<<" "<<price<<endl;

    return 0;
}
