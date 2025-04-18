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
struct node
{
    int pref, suff, sum, ans;
};

int N;
vector<int> arr;
vector<node> tree;

void build(int index, int st, int end)
{
    if (st == end)
    {
        if (arr[st] < 0)
        {
            tree[index].pref = 0;
            tree[index].suff = 0;
            tree[index].sum = arr[st];
            tree[index].ans = 0;
        }
        else
        {
            tree[index].pref = arr[st];
            tree[index].suff = arr[st];
            tree[index].sum = arr[st];
            tree[index].ans = arr[st];
        }
        return;
    }
    int mid = (st + end) / 2;
    build(2 * index + 1, st, mid);
    build(2 * index + 2, mid + 1, end);

    tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
    tree[index].pref = max({tree[2 * index + 1].pref, tree[2 * index + 1].sum + tree[2 * index + 2].pref,
                            tree[2 * index + 1].sum});
    tree[index].suff = max({tree[2 * index + 2].suff, tree[2 * index + 2].sum + tree[2 * index + 1].suff,
                            tree[2 * index + 2].sum});
    tree[index].ans = max({tree[2 * index + 1].ans, tree[2 * index + 1].suff + tree[2 * index + 2].pref,
                           tree[2 * index + 2].ans});
}

void update(int index, int st, int end, int idx, int val)
{
    if (st == end)
    {
        arr[st] = val;
        if (val < 0)
        {
            tree[index].pref = 0;
            tree[index].suff = 0;
            tree[index].sum = val;
            tree[index].ans = 0;
        }
        else
        {
            tree[index].pref = val;
            tree[index].suff = val;
            tree[index].sum = val;
            tree[index].ans = val;
        }
        return;
    }
    int mid = (st + end) / 2;
    if (mid >= idx)
    {
        update(2 * index + 1, st, mid, idx, val);
    }
    else
    {
        update(2 * index + 2, mid + 1, end, idx, val);
    }
    tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
    tree[index].pref = max({tree[2 * index + 1].pref, tree[2 * index + 1].sum + tree[2 * index + 2].pref,
                            tree[2 * index + 1].sum});
    tree[index].suff = max({tree[2 * index + 2].suff, tree[2 * index + 2].sum + tree[2 * index + 1].suff,
                            tree[2 * index + 2].sum});
    tree[index].ans = max({tree[2 * index + 1].ans, tree[2 * index + 1].suff + tree[2 * index + 2].pref,
                           tree[2 * index + 2].ans});
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    N = n;

    arr.resize(n);
    tree.resize(4*n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, N - 1);
    cout << tree[0].ans << endl;

    for (int i = 0; i < q; i++)
    {
        int idx, val;
        cin >> idx >> val;
        update(0, 0, N - 1, idx, val);
        cout << tree[0].ans << endl;
    }

    return 0;
}