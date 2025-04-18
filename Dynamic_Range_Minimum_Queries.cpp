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

int n;

vector<int> tree, a;

void build(int index, int l, int r)
{
    if (l == r)
    {
        tree[index] = a[l];
        return;
    }
    int mid = (l + r) / 2;

    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int index, int l, int r, int lq, int rq)
{
    if (lq > r || rq < l)
        return INT_MAX;

    if (l >= lq && rq >= r)
    {
        return tree[index];
    }

    int mid = (l + r) / 2;
    int q1 = query(2 * index, l, mid, lq, rq);
    int q2 = query(2 * index + 1, mid + 1, r, lq, rq);

    return min(q1, q2);
}

void update(int index, int l, int r, int idx, int val)
{
    if (l == r)
    {
        tree[index] = val;
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
    {
        update(2 * index, l, mid, idx, val);
    }
    else
    {
        update(2 * index + 1, mid + 1, r, idx, val);
    }
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, q;
    cin >> size >> q;
    n = size;

    tree.resize(4 * n);
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);

    while (q--)
    {
        int t, p, k;
        cin >> t >> p >> k;

        if (t == 1)
        {
            p--;
            update(1, 0, n - 1, p, k);
        }
        else
        {
            p--;
            k--;
            int ans = query(1, 0, n - 1, p, k);
            cout << ans << endl;
        }
    }

    return 0;
}
