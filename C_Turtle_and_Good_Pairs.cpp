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
string minimizeAdjacentDuplicates(string s) {
    vector<int> freq(26, 0); 

    for (char c : s) {
        freq[c - 'a']++;
    }

    vector<pair<int, char>> freqVec;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            freqVec.push_back({freq[i], char('a' + i)});
        }
    }

    sort(freqVec.rbegin(), freqVec.rend());

    int n = s.size();
    string result(n, ' ');

    int idx = 0;
    for (auto& p : freqVec) {
        char c = p.second;
        int count = p.first;

        while (count > 0 && idx < n) {
            result[idx] = c;
            idx += 2;
            count--;
        }
    }

    idx = 1;
    for (auto& p : freqVec) {
        char c = p.second;
        int count = p.first;

        while (count > 0) {
            if (idx >= n) idx = 1; 

            result[idx] = c;
            idx += 2;
            count--;
        }
    }

    return result;
}
void solve() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    string ans = minimizeAdjacentDuplicates(s);
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}