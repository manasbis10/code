#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(n + m + 1), t(n + m + 1);
    int size = n + m + 1;
    for (int i = 0; i < n + m + 1; i++)
        cin >> p[i];
    for (int i = 0; i < n + m + 1; i++)
        cin >> t[i];

    vector<int> ans;

    // for(int i = 1;i<size;i++)
    // {
    //     p[i] += p[i-1];
    // }
    // for(int i = 1;i<size;i++)
    // {
    //     t[i] += t[i-1];
    // }
int preq = n, treq = m;
int sum = 0;
    for(int i = 0;i<1;i++)
    {
        
        
        for(int j = 0;j<size;j++)
        {
            if(j!=i)
            {
                if(p[j]>t[j] && preq) 
                {
                    
                    sum+=p[j];
                    p[j] = -1*p[j];
                    preq--;
                }
                else if(p[j]<t[j] && treq)
                {
                    sum+=t[j];
                    t[j] = -1*t[j];
                    
                    treq--;
                }
                else if(p[j]>t[j] && preq==0)
                {
                     sum+=t[j];
                    t[j] = -1*t[j];
                   
                    treq--;

                }
                else if(p[j]<t[j] && treq==0)
                {
                    sum+=p[j];
                    p[j] = -1*p[j];
                    
                    preq--;

                }

            }
        }
        if(sum!=0)
        ans.push_back(sum);
    }
    for(int j = 1;j<size;j++)
    {
        if(p[j]<0)
        {
            p[j] = -1*p[j];
            preq++;
            sum -=p[j];
        }
        else if(t[j]<0)
        {
            t[j] = -1*t[j];
            treq++;
            sum -=t[j];
        }

        if(preq>0)
        {
            sum+=p[j-1];
            p[j-1] = -1*p[j-1];
            preq--;
        }else{
            sum+=t[j-1];
            t[j-1] = -1*t[j-1];
            treq--;

        }
        ans.push_back(sum);

    }

    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}
