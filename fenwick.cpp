#include<bits/stdc++.h>

using namespace std;

struct fenwick{
    int n;
    vector<int>f;

    fenwick(int n)
    {
        this->n = n;
        f.resize(n+1, 0);
    }

    void update(int i, int num)
    {
        for(;i<=n;i += (i & -i))
        {
            f[i] += num;
        }
    }
    int query(int i)
    {
        int sum = 0;
        for(;i>0;i -= (i & -i))
        {
            sum += f[i];
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l-1);
    }


};