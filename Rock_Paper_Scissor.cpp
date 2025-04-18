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
int n, k;
int dp[1001][1001][4];  // Adjusted size to handle prev = -1 to 2
int back[1001][1001][4];
unordered_map<char, int> mp;
unordered_map<int, char> rmp;

int check(int a, int b)
{
    if(b == 0)return a == 2;
    if(b == 1)return a == 0;
    if(b == 2)return a == 1;
    return 0;
}

int solve(int i, int k, int prev, vector<int>& arr)
{
    if(k < 0)
    {
        return -1e9;
    }
    if(i == n)
    {
        return 0;
    }
    if(dp[i][k][prev + 1] != -1) return dp[i][k][prev + 1];

    int ans = -1e9;
    int best_j = -1;
    for(int j = 0; j < 3; j++)
    {
        int change = (i == 0 || j == prev) ? 0 : 1;  // Do not count change at position 0
        if(k - change < 0) continue;  // Prune invalid states
        int temp = check(j, arr[i]) + solve(i + 1, k - change, j, arr);
        if(temp > ans)
        {
            ans = temp;
            best_j = j;
        }
        else if(temp == ans && j < best_j)
        {
            best_j = j;  // Choose the lexicographically smallest move
        }
    }
    back[i][k][prev + 1] = best_j;
    return dp[i][k][prev + 1] = ans;
}

string final_ans;
void generate(int i, int k, int prev, vector<int>& arr)
{
    if(i == n) return;
    int j = back[i][k][prev + 1];
    final_ans += rmp[j];
    int change = (prev == -1 || j == prev) ? 0 : 1;
    generate(i + 1, k - change, j, arr);
}

void solve_problem() {
    memset(dp, -1, sizeof(dp));
    final_ans = "";
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        arr[i] = mp[s[i]];
    }

    int ans = solve(0, k, -1, arr);  // Start with prev = -1

    cout << ans << endl;
    generate(0, k, -1, arr);
    cout << final_ans << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    mp['P'] = 0;
    mp['R'] = 1;
    mp['S'] = 2;

    rmp[0] = 'P';
    rmp[1] = 'R';
    rmp[2] = 'S';

    while (tc--) {
        solve_problem();
    }

    return 0;
}
