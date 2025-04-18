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
vector<int> check(string &a, string &b)
{
    int n = a.length();
    vector<int>prefix(a.length());
    vector<int>freq(26);
    for(int i = 0;i<n;i++)
    {
        freq[a[i] - 'a']++;
        freq[b[i] - 'a']--;
        int cnt = 0;
        for(int j = 0;j<26;j++)
        {
            if(freq[j]>0)
            {
                cnt++;
            }

        }
        prefix[i] = cnt;

    }

    
   
    return prefix;
    
}
#define ALPHABET_SIZE 26

void computePrefixFrequency(const string& s, vector<vector<int>>& prefixFreq) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                prefixFreq[i][j] = prefixFreq[i - 1][j];
            }
        }
        prefixFreq[i][s[i] - 'a']++;
    }
}

int minChangesForAnagram(int l, int r, const vector<vector<int>>& prefixFreq1, const vector<vector<int>>& prefixFreq2) {
    vector<int> freq1(ALPHABET_SIZE, 0);
    vector<int> freq2(ALPHABET_SIZE, 0);

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        freq1[i] = prefixFreq1[r][i] - (l > 0 ? prefixFreq1[l - 1][i] : 0);
        freq2[i] = prefixFreq2[r][i] - (l > 0 ? prefixFreq2[l - 1][i] : 0);
    }

    int changes = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        changes += abs(freq1[i] - freq2[i]);
    }
    return changes / 2;
}   
void solve() {
     int n, q;
     cin>>n>>q;

     string a, b;
     cin>>a>>b;

    //  vector<int>prefix = check(a,b);

     vector<vector<int>> prefixFreq1(n, vector<int>(ALPHABET_SIZE, 0));
    vector<vector<int>> prefixFreq2(n, vector<int>(ALPHABET_SIZE, 0));

    computePrefixFrequency(a, prefixFreq1);
    computePrefixFrequency(b, prefixFreq2);

     while(q--)
     {
        int l,r;
        cin>>l>>r;
        l--;
        r--;

       // int left = (l==0) ? 0 : prefix[l-1];
        int ans = minChangesForAnagram(l, r, prefixFreq1, prefixFreq2);
        cout<<ans<<endl;
     }
  

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