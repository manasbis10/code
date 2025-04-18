#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_sub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int bin_exp(int base, int exp, int m)
{
    if (exp == 0)
        return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0)
    {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) { return bin_exp(a, m - 2, m); }
/*---------------------------------------------------------------------------------------*/
int get_sum(int num)
{
    if (num == 0)
        return 0;
    return (num * (num + 1)) / 2;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    vector<int> t;
    stack<pair<int, int>> st;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            if (t.empty())
            {
                t.push_back(arr[i]);
                if (i == n - 1)
                {
                    if (arr[i - 1] - arr[i] > n)
                    {
                        cout << 0 << endl;
                        return;
                    }
                    st.push({arr[i - 1] - arr[i], n});
                }
                else
                {

                    if (arr[i - 1] - arr[i] > n)
                    {
                        cout << 0 << endl;
                        return;
                    }
                    st.push({arr[i - 1] - arr[i], min(n, arr[i + 1] - arr[i])});
                }
            }
            else
            {
                if (t.back() > arr[i])
                {
                    cout << 0 << endl;
                    return;
                }
                else
                {
                    t.push_back(arr[i]);
                    if (i == n - 1)
                    {
                        if (arr[i - 1] - arr[i] > n)
                        {
                            cout << 0 << endl;
                            return;
                        }
                        st.push({arr[i - 1] - arr[i], n});
                    }
                    else
                    {

                        if (arr[i - 1] - arr[i] > n)
                        {
                            cout << 0 << endl;
                            return;
                        }
                        st.push({arr[i - 1] - arr[i], min(n, arr[i + 1] - arr[i])});
                    }
                }
            }
        }
    }
    if(st.empty())
    {
        cout<<get_sum(n)<<endl;
        return;
    }
    while(st.size() > 1)
    {
        auto top = st.top();
        st.pop();

        auto top1 = st.top();
        st.pop();

        if(top.first<= top1.first && top1.second<=  top.second)
        {
            st.push({top1.first, top1.second});
        }
        else if(top1.first<= top.first && top.second<=  top1.second)
        {
            st.push({top.first, top.second});

        }
        else
        {
            cout<<0<<endl;
            return;
        }

    }

    auto top = st.top();
    int mini = top.first, maxi = top.second;
    int ans = max({0LL, get_sum(maxi) - get_sum(mini - 1)});
    cout << ans << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    string s = "2", s1 = "12";
    if(s<s1) cout<<"hello";
    else cout<<"no";

    while (tc--)
    {
        solve();
    }

    return 0;
}