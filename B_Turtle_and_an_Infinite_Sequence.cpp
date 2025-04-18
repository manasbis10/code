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
// Node structure for Sparse Segment Tree
struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
};

class SparseSegmentTree {
    Node* root;
    int n;

    void update(Node*& node, int start, int end, int idx, int value) {
        if (node == nullptr) node = new Node();
        if (start == end) {
            node->val = value;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(node->left, start, mid, idx, value);
        else
            update(node->right, mid + 1, end, idx, value);
        node->val = (node->left ? node->left->val : 0) | (node->right ? node->right->val : 0);
    }

    int query(Node* node, int start, int end, int l, int r) {
        if (node == nullptr || r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return node->val;
        int mid = (start + end) / 2;
        return query(node->left, start, mid, l, r) | query(node->right, mid + 1, end, l, r);
    }

public:
    SparseSegmentTree(int size) : n(size) {
        root = new Node();
    }

    void update(int idx, int value) {
        update(root, 0, n - 1, idx, value);
    }

    int query(int l, int r) {
        return query(root, 0, n - 1, l, r);
    }
};
void solve(SparseSegmentTree segTree)
{
    int n, m;
    cin >> n >> m;

    if(m==0)
    {
        cout<<n<<endl;
        return;
    }
    int l = max(0LL, n-m);
    int r = n+m;


    
    cout <<  segTree.query(l,r)<< endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SparseSegmentTree segTree(1e9);
    int tc;
    cin >> tc;

    while (tc--)
    {
        solve(segTree);
    }

    return 0;
}
